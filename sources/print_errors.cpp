// print_errors.cpp -- файл печатающий ошибки

#include <stdio.h>
#include <stdlib.h>
#include "solve_func.h"
#include "my_printf.h"
#include "print_errors.h"

void printErrorLines(const char * file, const char * func, long int line_number) {
  colorPrintf(RED, BOLD, "file: %s func: %s line: %d\n", file, func, line_number);
  char line[MAX_LINE];
  FILE * fp;
  fp = fopen(file, "r");
  for (int i = 0; i <= line_number; i++) {
    fgets(line, MAX_LINE, fp);
    if (i >= line_number - 2)
      colorPrintf(RED, BOLD, "%s", line);
  }
  abort();
}

void errorsParser(enum Errors error) {
  switch (error) {
    case SUCCESS:
      break;
    case UNKNOWN_NUMBER_OF_ROOTS:
      colorPrintf(RED, PRIMARY, "Некорректное количество корней.");
      break;
    case NULL_POINTER_FAILURE:
      colorPrintf(RED, PRIMARY, "Нулевой указатель.");
      break;
    default:
      colorPrintf(RED, PRIMARY, "Непредвиденная ошибка.");
      break;
  }
}
