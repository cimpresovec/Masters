#include "raymath.h"
#include "BreakoutBall.hpp"
#include "AssetManager.h"
#include "Globals.h"

BreakoutBall::BreakoutBall()
{
    velocity = Vector2Scale(Vector2Normalize(velocity), maxSpeed);
}

void BreakoutBall::finishMoving()
{
    position = expectedPosition;

    this->checkOutOfBounds();
}

void BreakoutBall::checkOutOfBounds()
{
    if (numberOfLives < 0) return;

    if (position.y > 720)
    {
        numberOfLives--;
        if (numberOfLives >= 0) holding = true;
    }
}

void BreakoutBall::playSoundEffect()
{
    if (soundEffectBlip) PlaySound(AssetManager::getInstance().getSound("blip"));
    else PlaySound(AssetManager::getInstance().getSound("blop"));
    soundEffectBlip = !soundEffectBlip;
}

void BreakoutBall::startMoving(const float deltaTime)
{
    expectedPosition.x = position.x + velocity.x * deltaTime;
    expectedPosition.y = position.y + velocity.y * deltaTime;
}

void BreakoutBall::checkCollisionAgainstWalls(std::vector<BreakoutWall>& walls)
{
    for (auto& wall : walls)
    {
        if (CheckCollisionCircleRec(expectedPosition, radius, wall.getCollisionRectangle()))
        {
            //Check collision direction by moving back on one axis and rechecking
            float previousX = expectedPosition.x;
            expectedPosition.x = position.x;
            if (CheckCollisionCircleRec(expectedPosition, radius, wall.getCollisionRectangle()))
            {
                expectedPosition.y = position.y;
                expectedPosition.x = previousX;
                velocity.y = -velocity.y;
            } //Horizontal movement caused the collision
            else
            {
                velocity.x = -velocity.x;
            }

            this->playSoundEffect();
        }
    }
}

void BreakoutBall::checkCollisionAgainstBricks(std::vector<BreakoutBrick>& bricks)
{
    for (auto& brick : bricks)
    {
        //Code duplication with walls, TODO refactor out
        if (CheckCollisionCircleRec(expectedPosition, radius, brick.getCollisionRectangle()))
        {
            brick.destroy();

            //Check collision direction by moving back on one axis and rechecking
            float previousX = expectedPosition.x;
            expectedPosition.x = position.x;
            if (CheckCollisionCircleRec(expectedPosition, radius, brick.getCollisionRectangle()))
            {
                expectedPosition.y = position.y;
                expectedPosition.x = previousX;
                velocity.y = -velocity.y;
            } //Horizontal movement caused the collision
            else
            {
                velocity.x = -velocity.x;
            }

            this->playSoundEffect();
        }
    }
}

void BreakoutBall::checkCollisionAgainstPlayer(const BreakoutPad pad)
{
    if (holding) return this->moveWithPad(pad);

    Rectangle padCollisionRectangle = pad.getCollisionRectangle();
    if (CheckCollisionCircleRec(expectedPosition, radius, padCollisionRectangle))
    {
        expectedPosition.y = position.y;

        //Control direction based on hit location
        float horizontalDifference = position.x - (padCollisionRectangle.x + padCollisionRectangle.width / 2);
        horizontalDifference /= (padCollisionRectangle.width);

        velocity.x = horizontalDifference * maxSpeed * 2; //Prefer horizontal over vertical movement
        velocity.y = -velocity.y;
        velocity = Vector2Scale(Vector2Normalize(velocity), maxSpeed);
        expectedPosition.y = padCollisionRectangle.y - radius;
        this->playSoundEffect();
    }
}

void BreakoutBall::moveWithPad(const BreakoutPad pad)
{
    Rectangle padCollisionRectangle = pad.getCollisionRectangle();
    expectedPosition.x = padCollisionRectangle.x + padCollisionRectangle.width / 2;
    expectedPosition.y = padCollisionRectangle.y - radius;
}

void BreakoutBall::shoot()
{
    holding = false;
}

void BreakoutBall::render()
{
    DrawTexturePro(AssetManager::getInstance().getTexture("ball"),
                   AssetManager::getInstance().getRectangle("ball"),
                   Rectangle{int(position.x - radius), int(position.y - radius), int(radius * 2), int(radius * 2)},
                   Vector2{0, 0},
                   0,
                   ORANGE);
//    DrawCircle(int(position.x), int(position.y), radius, RED);
}
