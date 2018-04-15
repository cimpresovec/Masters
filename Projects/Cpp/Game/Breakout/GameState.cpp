#include "GameState.hpp"
#include <cmath>

GameState::GameState()
{
    camera.target = Vector2{1280 / 2, 720 / 2};
    camera.zoom = fminf(GetScreenWidth() / 1280.f, GetScreenHeight() / 720.f);
    camera.offset = Vector2{(GetScreenWidth() - 1280) / 2.f, (GetScreenHeight() - 720) / 2.f};
    camera.rotation = 0;
}

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
