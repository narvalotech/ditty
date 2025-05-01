#ifndef NGL_H_
#define NGL_H_

#include <stddef.h>
#include <stdbool.h>

typedef bool (loop_callback_t)(void);

void ngl_init(void *context, size_t width, size_t height);
void ngl_start_loop(loop_callback_t *cb);
void ngl_clear(void);

#endif // NGL_H_
