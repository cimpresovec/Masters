#ifndef BREAKOUTBALL_HPP
#define BREAKOUTBALL_HPP

#include <raylib.h>
#include <vector>

#include "BreakoutWall.hpp"
#include "BreakoutPad.hpp"
#include "BreakoutBrick.hpp"

class BreakoutBall
{
    Vector2 position{400, 600};
    Vector2 expectedPosition{};
    float radius = 10;
    Vector2 velocity{0, -10};
    float maxSpeed = 500;
    bool holding = true;
    bool soundEffectBlip = true;
public:
    BreakoutBall();

    void startMoving(const float deltaTime);
    void finishMoving();
    void checkCollisionAgainstWalls(std::vector<BreakoutWall>& walls);
    void checkCollisionAgainstBricks(std::vector<BreakoutBrick>& bricks);
    void checkCollisionAgainstPlayer(const BreakoutPad pad);
    void shoot();
    void render();
private:
    void moveWithPad(const BreakoutPad pad);
    void checkOutOfBounds();
    void playSoundEffect();
};

#endif // BREAKOUTBALL_HPP
