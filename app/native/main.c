#include "raylib.h"

int main(void)
{
    // Initialize the window
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Raylib Rectangle Example");

    // Set target FPS
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // Draw a rectangle
            DrawRectangle(300, 200, 200, 100, RED);

            DrawText("This is a red rectangle", 300, 320, 20, DARKGRAY);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}
