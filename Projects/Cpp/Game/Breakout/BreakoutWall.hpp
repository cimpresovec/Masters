#ifndef BREAKOUTWALL_HPP
#define BREAKOUTWALL_HPP

#include <raylib.h>

class BreakoutWall
{
    Rectangle collisionRectangle{0, 0, 0, 0};
    Rectangle renderRectangle{0, 0, 0, 0};
    Vector2 wigglePower{-1, 0};
    float timer = 0;
public:
    BreakoutWall(const Rectangle renderRectangle);
    void render();
    Rectangle getCollisionRectangle();
    void applyForce(const Vector2 force);
};

#endif // BREAKOUTWALL_HPP
