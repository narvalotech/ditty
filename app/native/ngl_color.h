#ifndef NGL_COLOR_H_
#define NGL_COLOR_H_

#include <stdint.h>

struct ngl_color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

#define NGLC(...) &((struct ngl_color){__VA_ARGS__})

#define NGLC_BLACK    NGLC( 0, 0, 0, 255 )
#define NGLC_OFFWHITE NGLC( 245, 245, 245, 255 )

#endif // NGL_COLOR_H_
