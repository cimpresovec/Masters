#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.hpp"

class MainMenuState : public GameState
{
    Rectangle buttonPlay = {640 - 150, 300, 300, 100};
    Rectangle buttonExit = {640 - 150, 500, 300, 100};
    bool mouseClicked = false;
public:
    MainMenuState();

    void handleEvents() override;
    void handleLogic(float deltaTime) override;
    void handleRendering() override;
private:
    void changeStateToLevel();
};

#endif // MAINMENUSTATE_H
