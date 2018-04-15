#ifndef TITLESTATE_H
#define TITLESTATE_H

#include "GameState.hpp"

class TitleState : public GameState
{
    float timer = 0;
    float alpha = 0;
public:
    TitleState();

    void handleEvents() override;
    void handleLogic(float deltaTime) override;
    void handleRendering() override;
};

#endif // TITLESTATE_H
