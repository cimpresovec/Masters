#include "BreakoutBrick.hpp"

BreakoutBrick::BreakoutBrick(const Vector2 position)
{
    collisionRectangle.x = int(position.x);
    collisionRectangle.y = int(position.y);
}

void BreakoutBrick::render()
{
    DrawRectanglePro(collisionRectangle, Vector2{}, 0, ORANGE);
}

Rectangle BreakoutBrick::getCollisionRectangle()
{
    return collisionRectangle;
}

void BreakoutBrick::destroy()
{
    _shouldDestroy = true;
}

bool BreakoutBrick::shouldDestroy()
{
    return _shouldDestroy;
}
