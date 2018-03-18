#include "GameState.hpp"

void GameState::changeGameState(const GameStates state)
{
    this->nextGameState = state;
}

GameState::~GameState() {}

GameStates GameState::getNextState() const
{
    return nextGameState;
}

Camera2D GameState::getCamera() const
{
    return camera;
}
