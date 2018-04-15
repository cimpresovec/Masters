#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <raylib.h>

enum GameStates
{
    STATE_NULL,
    STATE_TITLE,
    STATE_MAINMENU,
    STATE_LEVEL,
    STATE_EXIT
};

class GameState
{
protected:
    Camera2D camera{};
    GameStates currentGameState = GameStates::STATE_NULL;
    GameStates nextGameState = GameStates::STATE_NULL;
public:
    GameState();
    virtual ~GameState();
    virtual void handleEvents() = 0;
    virtual void handleLogic(const float deltaTime) = 0;
    virtual void handleRendering() = 0;

    GameStates getNextState() const;
    Camera2D getCamera() const;

    void changeGameState(const GameStates state);
};

#endif // GAMESTATE_HPP
