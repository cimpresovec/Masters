#include <raylib.h>
#include <cmath>

int main()
{
    InitWindow(800, 600, "Space Invaders");
//    SetExitKey(0);
    float offset = 0.f;

    while (!WindowShouldClose())
    {
        //Event handling

        //Logic
        offset = fmodf(offset + GetFrameTime(), 2 * PI);

        //Rendering
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Empty project", 400 - MeasureText("Empty project", 20) / 2, 300 + int(sinf(offset) * 30), 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
