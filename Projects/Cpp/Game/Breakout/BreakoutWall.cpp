#include "BreakoutWall.hpp"
#include "raymath.h"
#include "easings.h"
#include "AssetManager.h"
#include <iostream>

BreakoutWall::BreakoutWall(const Rectangle shape)
{
    this->renderRectangle = shape;
    this->collisionRectangle = shape;
}

void BreakoutWall::render()
{
    DrawTexturePro(AssetManager::getInstance().getTexture("wall"),
                   AssetManager::getInstance().getRectangle("wall"),
                   renderRectangle,
                   Vector2{0, 0},
                   0,
                   BLUE);
//    DrawRectanglePro(renderRectangle, Vector2{}, 0, BLUE);
}

Rectangle BreakoutWall::getCollisionRectangle()
{
    return collisionRectangle;
}
