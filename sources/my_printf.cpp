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

// прочитать про submodules, в общем сделать

// и свой ассерт, сделать его дефайном, который будет принимать условие bool и также будет принимать макросы
// описывающее номер строки, имя файла и функцию
// assert main.cpp: main() error on 16 line
// надо будет короче выводить еще саму строку в которой ошибка
// FILE* fopen
