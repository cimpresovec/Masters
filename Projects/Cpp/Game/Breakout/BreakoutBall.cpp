#include "BreakoutBall.hpp"

BreakoutBall::BreakoutBall()
{

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

void BreakoutBall::checkCollisionAgainstWalls(const std::vector<BreakoutWall> walls)
{
    for (auto wall : walls)
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
        }
    }
}

void BreakoutBall::checkCollisionAgainstPlayer(const BreakoutPad pad)
{
    if (CheckCollisionCircleRec(expectedPosition, radius, pad.getCollisionRectangle()))
    {
        expectedPosition.y = position.y;
        velocity.y = -velocity.y;
    }

    //TODO Side bumps
}

void BreakoutBall::render()
{
    DrawCircle(int(position.x), int(position.y), radius, RED);
}
