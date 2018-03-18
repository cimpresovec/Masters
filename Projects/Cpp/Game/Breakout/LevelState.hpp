#ifndef LEVELSTATE_HPP
#define LEVELSTATE_HPP

#include <vector>
#include "GameState.hpp"
#include "BreakoutPad.hpp"
#include "BreakoutBall.hpp"
#include "BreakoutWall.hpp"

class LevelState : public GameState
{
    BreakoutPad playerPad{};
    BreakoutBall ball{};
    std::vector<BreakoutWall> walls{};

public:
    LevelState();
    ~LevelState() override;
    void handleEvents() override;
    void handleLogic(const float deltaTime) override;
    void handleRendering() override;
};

#endif // LEVELSTATE_HPP
