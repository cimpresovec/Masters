#include "BreakoutWall.hpp"
#include "Utility.hpp"

BreakoutWall::BreakoutWall(const Rectangle shape)
{
    this->renderRectangle = shape;
    this->collisionRectangle = shape;
}

void BreakoutWall::render()
{
    //Refactor into some Wiggle Singleton?
    timer += GetFrameTime() * 10;
    renderRectangle = collisionRectangle;
    renderRectangle.x += int(sinf(timer) * wigglePower.x * 10);
    DrawRectanglePro(renderRectangle, Vector2{}, 0, BLUE);
    wigglePower.x = wigglePower.x - copysignf(1.f * GetFrameTime(), wigglePower.x);
    if (vector2Length(wigglePower) < 0.1f) wigglePower = Vector2{0, 0};
}

Rectangle BreakoutWall::getCollisionRectangle()
{
    return collisionRectangle;
}

void BreakoutWall::applyForce(const Vector2 force)
{
    wigglePower = force;
    timer = 0;
}
