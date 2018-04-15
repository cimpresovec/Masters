#include <cmath>
#include "BreakoutPad.hpp"
#include "BreakoutBall.hpp"
#include "AssetManager.h"

BreakoutPad::BreakoutPad()
{

}

void BreakoutPad::handleInput()
{
    keyLeft = IsKeyDown(KEY_LEFT);
    keyRight = IsKeyDown(KEY_RIGHT);
    keyShoot = IsKeyDown(KEY_SPACE);
}

void BreakoutPad::handleLogic(const float deltaTime, BreakoutBall& ball)
{
    velocity.x = 0;
    if (keyLeft) velocity.x += -horizontalSpeed;
    if (keyRight) velocity.x += horizontalSpeed;

    position.x += velocity.x * deltaTime;

    //Clamping
    position.x = fminf(position.x, 1280 - size.x / 2);
    position.x = fmaxf(position.x, size.x / 2);

    this->shootBall(ball);
}

void BreakoutPad::shootBall(BreakoutBall& ball)
{
    if (!keyShoot) return;
    ball.shoot();
}

void BreakoutPad::render() const
{
    DrawTexturePro(AssetManager::getInstance().getTexture("pad"),
                   AssetManager::getInstance().getRectangle("pad"),
                   Rectangle{int(position.x), int(position.y), int(size.x), int(size.y)},
                   origin,
                   0,
                   RED);
//    DrawRectanglePro(Rectangle{int(position.x), int(position.y), int(size.x), int(size.y)}, origin, 0, RED);
}

Rectangle BreakoutPad::getCollisionRectangle() const
{
    return Rectangle{int(position.x - size.x / 2), int(position.y - size.y / 2), int(size.x), int(size.y)};
}
