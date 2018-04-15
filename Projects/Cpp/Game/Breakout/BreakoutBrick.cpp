#include "BreakoutBrick.hpp"
#include "AssetManager.h"

BreakoutBrick::BreakoutBrick(const Vector2 position)
{
    collisionRectangle.x = int(position.x);
    collisionRectangle.y = int(position.y);
    color = Color{u_char(GetRandomValue(0, 255)), u_char(GetRandomValue(0, 255)), u_char(GetRandomValue(0, 255)), 255};
}

void BreakoutBrick::render()
{
    DrawTexturePro(AssetManager::getInstance().getTexture("brick"),
                   AssetManager::getInstance().getRectangle("brick"),
                   collisionRectangle,
                   Vector2{0, 0},
                   0,
                   color);
//    DrawRectanglePro(collisionRectangle, Vector2{}, 0, ORANGE);
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
