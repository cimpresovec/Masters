#ifndef BREAKOUTBALL_HPP
#define BREAKOUTBALL_HPP

#include <raylib.h>
#include <vector>

#include "BreakoutWall.hpp"
#include "BreakoutPad.hpp"

class BreakoutBall
{
    Vector2 position{300, 200};
    Vector2 expectedPosition{};
    float radius = 10;
    Vector2 velocity{-200, -100};
public:
    BreakoutBall();

    void startMoving(const float deltaTime);
    void finishMoving();
    void checkCollisionAgainstWalls(const std::vector<BreakoutWall> walls);
    void checkCollisionAgainstPlayer(const BreakoutPad pad);
    void render();
};

#endif // BREAKOUTBALL_HPP
