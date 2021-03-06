#ifndef LEVELSTATE_HPP
#define LEVELSTATE_HPP

#include <vector>
#include "GameState.hpp"
#include "BreakoutPad.hpp"
#include "BreakoutBall.hpp"
#include "BreakoutWall.hpp"
#include "BreakoutBrick.hpp"

class LevelState : public GameState
{
    BreakoutPad playerPad{};
    BreakoutBall ball{};
    std::vector<BreakoutWall> walls{};
    std::vector<BreakoutBrick> bricks{};

public:
    LevelState();
    LevelState(int level);
    ~LevelState() override;
    void handleEvents() override;
    void handleLogic(const float deltaTime) override;
    void handleRendering() override;
};

#endif // LEVELSTATE_HPP
