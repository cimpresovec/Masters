#include "MainMenuState.h"
#include "AssetManager.h"
#include "Globals.h"
#include <raylib.h>

MainMenuState::MainMenuState() : GameState()
{
    currentGameState = STATE_MAINMENU;
}

void MainMenuState::handleEvents()
{
    if (IsKeyPressed(KEY_ESCAPE)) this->changeGameState(STATE_EXIT);
    if (IsKeyPressed(KEY_ENTER)) this->changeStateToLevel();
    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) mouseClicked = true;
}

void MainMenuState::changeStateToLevel()
{
    numberOfLives = 3;
    score = 0;
    currentLevel = 1;
    changeGameState(STATE_LEVEL);
}

void MainMenuState::handleLogic(float deltaTime)
{
    if (!mouseClicked) return;
    mouseClicked = false;

    if (CheckCollisionPointRec(GetMousePosition(), buttonPlay))
    {
        this->changeStateToLevel();
    }
    if (CheckCollisionPointRec(GetMousePosition(), buttonExit))
    {
        changeGameState(STATE_EXIT);
    }
}

void MainMenuState::handleRendering()
{
    DrawTexturePro(AssetManager::getInstance().getTexture("breakout"),
                   AssetManager::getInstance().getRectangle("breakout"),
                   Rectangle{1280 / 2 - 800 / 2, 30, 800, 200},
                   Vector2{0, 0},
                   0,
                   WHITE);

    DrawTexturePro(AssetManager::getInstance().getTexture("menuFiller1"),
                   AssetManager::getInstance().getRectangle("menuFiller1"),
                   Rectangle{100, 400, 180, 200},
                   Vector2{0, 0},
                   0,
                   WHITE);

    DrawTexturePro(AssetManager::getInstance().getTexture("menuFiller2"),
                   AssetManager::getInstance().getRectangle("menuFiller2"),
                   Rectangle{1000, 300, 250, 250},
                   Vector2{0, 0},
                   0,
                   WHITE);

    DrawTexturePro(AssetManager::getInstance().getTexture("playButton"),
                   AssetManager::getInstance().getRectangle("playButton"),
                   buttonPlay,
                   Vector2{0, 0},
                   0,
                   WHITE);

    DrawTexturePro(AssetManager::getInstance().getTexture("exitButton"),
                   AssetManager::getInstance().getRectangle("exitButton"),
                   buttonExit,
                   Vector2{0, 0},
                   0,
                   WHITE);
}
