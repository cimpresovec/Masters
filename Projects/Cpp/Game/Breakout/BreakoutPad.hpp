#ifndef BREAKOUTPAD_HPP
#define BREAKOUTPAD_HPP

#include <raylib.h>

class BreakoutPad
{
    Vector2 position{1280 / 2, 650};
    Vector2 size{100, 10};
    Vector2 origin{50, 5};
    Vector2 velocity{0,0};
    float horizontalSpeed = 200;
    bool keyLeft = false, keyRight = false;
public:
    BreakoutPad();

    void handleInput();
    void handleLogic(const float deltaTime);
    void render() const;

    Rectangle getCollisionRectangle() const;
};

#endif // BREAKOUTPAD_HPP
