#include <raylib.h>

int main()
{
    InitWindow(800, 400, "test");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("hello", 400, 200, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
