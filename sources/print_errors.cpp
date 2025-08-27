// print_errors.cpp -- файл с функциями, печатающими ошибки

#include <stdio.h>
#include <stdlib.h>

#include "solve.h"
#include "my_printf.h"
#include "print_errors.h"

/*!
 * @brief вспомогательная функция для myAssert, выводящая строчки в которых условие не выполнилось
 *
 * @param file название файла с ошибкой
 * @param func название функции с ошибкой
 * @param line_number номер строки с ошибкой
 */
void printErrorLines(const char * file, const char * func, size_t line_number) {
  colorPrintf(RED, BOLD, "file: %s:%zu\nfunc: %s\n", file, line_number, func);

  const int MAX_LINE = 150;
  char line[MAX_LINE] = {};
  FILE * fp = fopen(file, "r");

  for (size_t i = 0; i <= line_number; i++) {
    fgets(line, MAX_LINE, fp);
    if (i >= line_number - 2)
      colorPrintf(RED, BOLD, "%zu: %s", i, line);
  }

  fclose(fp);
}

/*!
 * @brief вывод ошибок в удобочитаемом формате
 *
 * @param error принимает на вход одну из константных ошибок
 */
void errorsParser(Errors error) {
  switch (error) {
    case SUCCESS:
      break;
    case ASSERT_FAILED:
      break;
    case UNKNOWN_NUMBER_OF_ROOTS:
      colorPrintf(RED, PRIMARY, "Некорректное количество корней.");
      break;
    default:
      colorPrintf(RED, PRIMARY, "Непредвиденная ошибка.");
      break;
  }
}
