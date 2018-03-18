#include <raylib.h>
#include <memory>
#include "LevelState.hpp"

int main()
{
    InitWindow(1280, 720, "Breakout");
    SetExitKey(0);
    SetTargetFPS(60);
    std::unique_ptr<GameState> currentState = std::make_unique<LevelState>();

    while (currentState->getNextState() != STATE_EXIT)
    {
        currentState->handleEvents();
        currentState->handleLogic(GetFrameTime());

        BeginDrawing();
        ClearBackground(RAYWHITE);

        Begin2dMode(currentState->getCamera());
        currentState->handleRendering();

        End2dMode();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
