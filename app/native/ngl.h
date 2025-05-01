#ifndef NGL_H_
#define NGL_H_

#include <stddef.h>
#include <stdbool.h>
#include "ngl_color.h"

typedef bool (*loop_callback_t) (void);

struct ngl_img {
    int width;
    int height;
    const char *xbm;
};

void ngl_init(void *context, size_t width, size_t height);
void ngl_start_loop(loop_callback_t cb);
void ngl_clear(void);
void ngl_draw_text(char *text, int x, int y, size_t size, struct ngl_color *color);
void ngl_draw_rectangle(int x, int y, int w, int h, struct ngl_color *color);
void ngl_draw_bitmap(const struct ngl_img *img, int x, int y, int mode);

#endif // NGL_H_
