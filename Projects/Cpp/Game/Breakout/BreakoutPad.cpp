#include <cmath>
#include "BreakoutPad.hpp"

BreakoutPad::BreakoutPad()
{

}

void BreakoutPad::handleInput()
{
    keyLeft = IsKeyDown(KEY_LEFT);
    keyRight = IsKeyDown(KEY_RIGHT);
}

void BreakoutPad::handleLogic(const float deltaTime)
{
    velocity.x = 0;
    if (keyLeft) velocity.x += -horizontalSpeed;
    if (keyRight) velocity.x += horizontalSpeed;

    position.x += velocity.x * deltaTime;

    //Clamping
    position.x = fminf(position.x, 1280 - size.x / 2);
    position.x = fmaxf(position.x, size.x / 2);
}

void BreakoutPad::render() const
{
    DrawRectanglePro(Rectangle{int(position.x), int(position.y), int(size.x), int(size.y)}, origin, 0, BLACK);
}

Rectangle BreakoutPad::getCollisionRectangle() const
{
    return Rectangle{int(position.x - size.x / 2), int(position.y - size.y / 2), int(size.x), int(size.y)};
}
