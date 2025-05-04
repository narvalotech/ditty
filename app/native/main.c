#include <stdint.h>
#include <string.h>
#include "lib/ngl.h"
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

#define PLAY_ICON_POS_X 30
#define PLAY_ICON_POS_Y 35

typedef uint32_t ms_t;
typedef uint32_t percent_t;
typedef int8_t semitones_t;

struct meta_track {
    const char *title;
    const char *artist;
    const char *album;
    const ms_t length;
};

struct meta_playing {
    ms_t now;
    bool playing;
    percent_t speed;
    semitones_t pitch;
};

#define MIN_TO_MS(minutes, seconds) (((minutes * 60) + seconds) * 1000)

void drawProgress(ms_t now, ms_t duration)
{
    uint8_t percent = 100 * now / duration;

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

void drawTitle(const char *title)
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

void ui_draw_playing(struct meta_track *track,
                     struct meta_playing *playing)
{
    drawTitle(track->title);
    drawProgress(playing->now,
                 track->length);
    drawPlayIcon(false);
}

static struct meta_track s_track = {
    .title = "Sandstorm",
    .artist = "Darude",
    .album = "Dune official soundtrack",
    .length = MIN_TO_MS(3, 27),
};

static struct meta_playing s_playing;

static ms_t time_get(void)
{
    return 0;
}

bool mainloop(void)
{
    ngl_clear();

    ms_t now = time_get();

    s_playing.now = 30 * 1000;

    /* time advances when:
     * - we are playing
     * - a whole ms has elapsed
     */

    ui_draw_playing(&s_track, &s_playing);

    return true;
}

int main(void)
{
    ngl_init(NULL, DISPLAY_WIDTH, DISPLAY_HEIGHT);

    ngl_start_loop(mainloop);

    return 0;
}
