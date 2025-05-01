#include "ngl.h"
#include "raylib.h"
#include <stddef.h>


void ngl_init(void *context, size_t width, size_t height)
{
    InitWindow(width, height, "🔥");
    SetTargetFPS(60);
}

void ngl_start_loop(loop_callback_t *cb)
{
    // Main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();

        if (!cb()) {
            break;
        }

        EndDrawing();
    }

    CloseWindow();
}

void ngl_clear(void)
{
    ClearBackground(RAYWHITE);
}
