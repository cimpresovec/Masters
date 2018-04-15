#ifndef BREAKOUTPAD_HPP
#define BREAKOUTPAD_HPP

#include <raylib.h>

class BreakoutBall;
class BreakoutPad
{
    Vector2 position{1280 / 2, 650};
    Vector2 size{150, 30};
    Vector2 origin{size.x / 2, size.y / 2};
    Vector2 velocity{0,0};
    float horizontalSpeed = 500;
    bool keyLeft = false, keyRight = false, keyShoot = false;
public:
    BreakoutPad();

    void handleInput();
    void handleLogic(const float deltaTime, BreakoutBall& ball);
    void render() const;

    Rectangle getCollisionRectangle() const;

private:
    void shootBall(BreakoutBall &ball);
};

#endif // BREAKOUTPAD_HPP
