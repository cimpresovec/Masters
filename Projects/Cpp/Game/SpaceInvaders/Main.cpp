#include <raylib.h>
#include <cmath>
#include <string>

void drawFancyTextInASquare(const std::string text, const float x, const float y, const int size, const Color& color)
{
    int textWidth = MeasureText(text.c_str(), size);
    DrawText(text.c_str(), int(x - textWidth / 2), int(y), size, color);
    DrawRectangleLines(int(x - textWidth / 2) - 5, int(y - 5), textWidth + 10, 20 + 10, color);
}

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
        drawFancyTextInASquare("Empty project", 400, 300 + int(sinf(offset) * 30), 20, BLACK);
//        DrawText("Empty project", 400 - MeasureText("Empty project", 20) / 2, 300 + int(sinf(offset) * 30), 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
