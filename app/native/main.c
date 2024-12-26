#include <stdint.h>
#include <string.h>
#include "raylib.h"

#define DISPLAY_WIDTH 320
#define DISPLAY_HEIGHT 172

#define PROGRESS_POX_X (5)
#define PROGRESS_POX_Y (DISPLAY_HEIGHT - 60)
#define PROGRESS_WIDTH (DISPLAY_WIDTH - 10)
#define PROGRESS_HEIGHT (20)
#define PROGRESS_MARGIN (4)

#define TITLE_POS_X (10)
#define TITLE_POS_Y (DISPLAY_HEIGHT - 30)
#define TITLE_MAX_LEN 26

#define PLAY_ICON_WIDTH 40
#define PLAY_ICON_POS_X 30
#define PLAY_ICON_POS_Y 35

void drawTitle(char *title)
{
    static char t[TITLE_MAX_LEN + 1] = {};

    size_t len = strlen(title);

    if (len > TITLE_MAX_LEN) {
        strncpy(t, title, TITLE_MAX_LEN - 2);
        t[TITLE_MAX_LEN - 2] = '.';
        t[TITLE_MAX_LEN - 1] = '.';
        t[TITLE_MAX_LEN] = 0;
    }

    DrawText(t, TITLE_POS_X, TITLE_POS_Y, 20, BLACK);
}

void drawProgress(uint8_t percent)
{
    /* Background */
    DrawRectangle(PROGRESS_POX_X, PROGRESS_POX_Y, PROGRESS_WIDTH, PROGRESS_HEIGHT, BLACK);

    uint8_t rem = 100 - percent;
    /* uint8_t rem = 100; */

    size_t width = (rem * PROGRESS_WIDTH / 100) - (2 * PROGRESS_MARGIN);
    size_t pos_x = PROGRESS_POX_X + PROGRESS_MARGIN - (2 * PROGRESS_MARGIN);
    pos_x += PROGRESS_WIDTH - width;

    /* Progress: white-out the remaining percentage. */
    DrawRectangle(pos_x,
                  PROGRESS_POX_Y + PROGRESS_MARGIN,
                  width,
                  PROGRESS_HEIGHT - (2 * PROGRESS_MARGIN),
                  RAYWHITE);
}

void drawPause(int x, int y, int width)
{
    int ax = x - (width / 2);
    int ay = y - (width / 2);

    /* Background is black */
    DrawRectangle(ax, ay, width, width, BLACK);

    /* Split into two bars by drawing white in the middle */
    DrawRectangle(ax + (width / 3), ay, width / 3 + 1, width, RAYWHITE);
}

void drawPlayIcon(bool playing)
{
    /* TODO: just use icons, man */
    if (playing) {
        Vector2 center = { PLAY_ICON_POS_X, PLAY_ICON_POS_Y };
        float radius = PLAY_ICON_WIDTH / 2;

        DrawPoly(center, 3, radius, 120, BLACK);
    } else {
        drawPause(PLAY_ICON_POS_X, PLAY_ICON_POS_Y, PLAY_ICON_WIDTH);
    }
}

int main(void)
{
    const int screenWidth = 320;
    const int screenHeight = 172;

    InitWindow(screenWidth, screenHeight, "ditty");
    SetTargetFPS(60);

    /* x/y starts at top-left */

    // Main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        drawProgress(33);
        drawTitle("Darude - Sandstorm (Dune official soundtrack)");
        drawPlayIcon(true);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
