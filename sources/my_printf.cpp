// my_printf.cpp -- изменение цвета и шрифта

#include <stdio.h>
#include <stdarg.h>
#include "func_for_equations.h"

void color_printf(enum Colors color, enum Fonts font, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  printf("\033[%d;%dm", color, font);
  vprintf(fmt, args);
  printf("\033[0m\n");
  va_end(args);
}
