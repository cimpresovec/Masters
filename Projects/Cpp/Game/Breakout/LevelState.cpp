#include <raylib.h>
#include <cmath>
#include <algorithm>
#include <string>
#include "LevelState.hpp"
#include "Globals.h"

LevelState::LevelState() : GameState()
{
}

LevelState::LevelState(int level) : GameState()
{
    currentGameState = STATE_LEVEL;

    walls.push_back(BreakoutWall{Rectangle{0, 0, 10, 640}}); //Left wall
    walls.push_back(BreakoutWall{Rectangle{0, 0, 1280, 10}}); //Top wall
    walls.push_back(BreakoutWall{Rectangle{1270, 0, 10, 640}}); //Right wall

    //Bricks
    for (int y = 100; y < 400; y += 50)
    for (int x = 50; x < 1250; x += 100)
    {
        bricks.push_back(BreakoutBrick(Vector2{float(x), float(y)}));
    }
//    bricks.push_back(BreakoutBrick(Vector2{ 50, 50 }));
}

LevelState::~LevelState()
{

}

void LevelState::handleEvents()
{
    if (IsKeyPressed(KEY_ESCAPE)) this->changeGameState(STATE_MAINMENU);
    playerPad.handleInput();
}

void LevelState::handleLogic(const float deltaTime)
{
    playerPad.handleLogic(deltaTime, ball);

    //Ball handling
    ball.startMoving(deltaTime);
    ball.checkCollisionAgainstWalls(walls);
    ball.checkCollisionAgainstBricks(bricks);
    ball.checkCollisionAgainstPlayer(playerPad);
    ball.finishMoving();

    //Bricks
    for (auto brick = std::begin(bricks); brick != std::end(bricks);)
    {
        if (brick->shouldDestroy())
        {
            brick = bricks.erase(brick);
            score += 10;
        }
        else
        {
            brick++;
        }
    }

    if (bricks.size() == 0)
    {
        currentLevel++;
        this->changeGameState(STATE_LEVEL);
    }
}

void LevelState::handleRendering()
{
    //Lives render
    DrawText(("Lives: " + std::to_string(numberOfLives < 0? 0 : numberOfLives)).c_str(), 10, 680, 30, BLACK);
    DrawText(("Score: " + std::to_string(score)).c_str(), 1270 - MeasureText(("Score: " + std::to_string(score)).c_str(), 30), 680, 30, BLACK);
    DrawText(("Level " + std::to_string(currentLevel)).c_str(), 640 - MeasureText(("Level " + std::to_string(currentLevel)).c_str(), 30), 680, 30, BLACK);

    for (auto& wall : walls)
    {
        wall.render();
    }

    for (auto& brick : bricks)
    {
        brick.render();
    }

    playerPad.render();
    ball.render();

    if (numberOfLives < 0)
    {
        DrawText("GAME OVER", 640 - MeasureText("GAME OVER", 40) / 2, 500, 40, BLACK);
    }
}
