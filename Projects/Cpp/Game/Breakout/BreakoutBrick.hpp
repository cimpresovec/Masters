#ifndef BREAKOUTBRICK_H
#define BREAKOUTBRICK_H

#include <raylib.h>

class BreakoutBrick
{
    Rectangle collisionRectangle{0, 0, 80, 30};
    bool _shouldDestroy = false;
    Color color {};
public:
    BreakoutBrick(const Vector2 position);

    void render();
    Rectangle getCollisionRectangle();
    void destroy();
    bool shouldDestroy();
};

#endif // BREAKOUTBRICK_H
