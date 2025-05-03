#include <stdint.h>
#include <string.h>
#include "raylib.h"
#include "ngl.h"
#include "images/images.h"

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

    ngl_draw_text(t, TITLE_POS_X, TITLE_POS_Y, 20, NGLC_BLACK);
}

void drawProgress(uint8_t percent)
{
    /* Background */
    ngl_draw_rectangle(PROGRESS_POX_X, PROGRESS_POX_Y, PROGRESS_WIDTH, PROGRESS_HEIGHT, NGLC_BLACK);

    uint8_t rem = 100 - percent;
    /* uint8_t rem = 100; */

    size_t width = (rem * PROGRESS_WIDTH / 100) - (2 * PROGRESS_MARGIN);
    size_t pos_x = PROGRESS_POX_X + PROGRESS_MARGIN - (2 * PROGRESS_MARGIN);
    pos_x += PROGRESS_WIDTH - width;

    /* Progress: white-out the remaining percentage. */
    ngl_draw_rectangle(pos_x,
                       PROGRESS_POX_Y + PROGRESS_MARGIN,
                       width,
                       PROGRESS_HEIGHT - (2 * PROGRESS_MARGIN),
                       NGLC_OFFWHITE);
}

void drawPlayIcon(bool playing)
{
    ngl_draw_bitmap(playing ? &img_play : &img_pause, PLAY_ICON_POS_X, PLAY_ICON_POS_Y, 0);
}

bool mainloop(void)
{
    ngl_clear();

    drawProgress(33);
    drawTitle("Darude - Sandstorm (Dune official soundtrack)");
    drawPlayIcon(false);

    return true;
}

int main(void)
{
    ngl_init(NULL, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    ngl_start_loop(mainloop);

    return 0;
}
