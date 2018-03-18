#include <raylib.h>
#include <cmath>
#include "LevelState.hpp"


LevelState::LevelState() : GameState()
{
    currentGameState = STATE_LEVEL;

    //TODO MOVE INTO GameState?
    camera.target = Vector2{1280 / 2, 720 / 2};
    camera.zoom = fminf(GetScreenWidth() / 1280.f, GetScreenHeight() / 720.f);
    camera.offset = Vector2{(GetScreenWidth() - 1280) / 2.f, (GetScreenHeight() - 720) / 2.f};
    camera.rotation = 0;

    walls.push_back(BreakoutWall{Rectangle{0, 0, 10, 640}}); //Left wall
    walls.push_back(BreakoutWall{Rectangle{0, 0, 1280, 10}}); //Top wall
    walls.push_back(BreakoutWall{Rectangle{1270, 0, 10, 640}}); //Right wall
}

LevelState::~LevelState()
{

}

void LevelState::handleEvents()
{
    if (IsKeyPressed(KEY_ESCAPE)) this->changeGameState(STATE_EXIT);
    playerPad.handleInput();
}

void LevelState::handleLogic(const float deltaTime)
{
    playerPad.handleLogic(deltaTime);

    //Ball handling
    ball.startMoving(deltaTime);
    ball.checkCollisionAgainstWalls(walls);
    ball.checkCollisionAgainstPlayer(playerPad);
    ball.finishMoving();
}

void LevelState::handleRendering()
{
    for (auto wall : walls)
    {
        wall.render();
    }

    playerPad.render();
    ball.render();
}
