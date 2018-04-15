#include <raylib.h>
#include <memory>
#include "LevelState.hpp"
#include "MainMenuState.h"
#include "TitleState.h"
#include "AssetManager.h"
#include "Globals.h"

int main()
{
    InitWindow(1280, 720, "Breakout");
    InitAudioDevice();
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    SetExitKey(0);
    SetTargetFPS(60);

    //Load assets
    AssetManager::getInstance().loadTexture("pad", "../assets/pad.png");
    AssetManager::getInstance().loadTexture("ball", "../assets/ball.png");
    AssetManager::getInstance().loadTexture("wall", "../assets/wall.png");
    AssetManager::getInstance().loadTexture("brick", "../assets/brick.png");
    AssetManager::getInstance().loadTexture("logo", "../assets/logo.png");
    AssetManager::getInstance().loadTexture("breakout", "../assets/breakout.png");
    AssetManager::getInstance().loadTexture("menuFiller1", "../assets/menuFiller1.png");
    AssetManager::getInstance().loadTexture("menuFiller2", "../assets/menuFiller2.png");
    AssetManager::getInstance().loadTexture("playButton", "../assets/playButton.png");
    AssetManager::getInstance().loadTexture("exitButton", "../assets/exitButton.png");

    Music music = LoadMusicStream("../assets/Wild_Pogo.ogg");
    PlayMusicStream(music);

    AssetManager::getInstance().loadSound("blip", "../assets/blip.wav");
    AssetManager::getInstance().loadSound("blop", "../assets/blop.wav");

    std::unique_ptr<GameState> currentState = std::make_unique<TitleState>();

    while (currentState->getNextState() != STATE_EXIT)
    {
        UpdateMusicStream(music);
        currentState->handleEvents();
        currentState->handleLogic(GetFrameTime());

        BeginDrawing();
        ClearBackground(RAYWHITE);

        Begin2dMode(currentState->getCamera());
        currentState->handleRendering();

        End2dMode();
        EndDrawing();

        //Change State
        switch (currentState->getNextState())
        {
            case STATE_MAINMENU:
            {
                currentState = std::make_unique<MainMenuState>();
                break;
            }
            case STATE_LEVEL:
            {
                currentState = std::make_unique<LevelState>(currentLevel);
                break;
            }
            default: break;
        }
    }

    UnloadMusicStream(music);
    CloseAudioDevice();

    CloseWindow();

    return 0;
}
