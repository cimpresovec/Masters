#ifndef BREAKOUTWALL_HPP
#define BREAKOUTWALL_HPP

#include <raylib.h>

class BreakoutWall
{
    Rectangle collisionRectangle{0, 0, 0, 0};
    Rectangle renderRectangle{0, 0, 0, 0};
public:
    BreakoutWall(const Rectangle renderRectangle);
    void render() const;
    Rectangle getCollisionRectangle();
};

#endif // BREAKOUTWALL_HPP
