#ifndef TRIK_STUDIO_UTILS_H_
#define TRIK_STUDIO_UTILS_H_

#include "kernel.h"
#include "osek_kernel.h"

extern void wait(unsigned long delay);
extern void ts_dispatch_timers();

extern char *concat(char *str1, char *str2);

extern char *int_to_string(int i);
extern char *float_to_string(float f);
extern char *bool_to_string(int b);
extern char *other_to_string(void *a);

#endif
