#include "BreakoutWall.hpp"

BreakoutWall::BreakoutWall(const Rectangle shape)
{
    this->renderRectangle = shape;
    this->collisionRectangle = shape;
}

void BreakoutWall::render() const
{
    DrawRectanglePro(renderRectangle, Vector2{}, 0, BLUE);
}

Rectangle BreakoutWall::getCollisionRectangle()
{
    return collisionRectangle;
}
