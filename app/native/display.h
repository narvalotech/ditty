#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stddef.h>
#include <stdbool.h>

typedef bool (loop_callback_t)(void);

void display_init(void *context, size_t width, size_t height);
void display_start_loop(loop_callback_t *cb);
void display_clear(void);

#endif // DISPLAY_H_
