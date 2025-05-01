#include "ngl.h"
#include "raylib.h"
#include <stddef.h>
#include <string.h>
#include <assert.h>


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

static Color from_nglc(struct ngl_color *color)
{
    _Static_assert(sizeof(Color) == sizeof(struct ngl_color));

    Color c;
    memcpy(&c, color, sizeof(c));

    return c;
}

void ngl_draw_text(char *text, int x, int y, size_t size, struct ngl_color *color)
{
    DrawText(text, x, y, size, from_nglc(color));
}

void ngl_draw_rectangle(int x, int y, int w, int h, struct ngl_color *color)
{
    DrawRectangle(x, y, w, h, from_nglc(color));
}