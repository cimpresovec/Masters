#include "raymath.h"
#include "BreakoutBall.hpp"

BreakoutBall::BreakoutBall()
{
    velocity = Vector2Scale(Vector2Normalize(velocity), maxSpeed);
}

void BreakoutBall::finishMoving()
{
    position = expectedPosition;
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
            wall.applyForce(Vector2{-1, 0});
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
        }
    }
}

void BreakoutBall::checkCollisionAgainstPlayer(const BreakoutPad pad)
{
    Rectangle padCollisionRectangle = pad.getCollisionRectangle();
    if (CheckCollisionCircleRec(expectedPosition, radius, padCollisionRectangle))
    {
        expectedPosition.y = position.y;

        //Control direction based on hit location
        float horizontalDifference = expectedPosition.x - (padCollisionRectangle.x + padCollisionRectangle.width / 2);
        horizontalDifference /= (padCollisionRectangle.width);

        velocity.x = horizontalDifference * maxSpeed * 2; //Prefer horizontal over vertical movement
        velocity.y = -velocity.y;
        velocity = Vector2Scale(Vector2Normalize(velocity), maxSpeed);
    }

    //TODO Handle side bumps?
}

void BreakoutBall::render()
{
    DrawCircle(int(position.x), int(position.y), radius, RED);
}
