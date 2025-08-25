// print_errors.cpp -- файл печатающий ошибки

#include <stdio.h>
#include <stdlib.h>

#include "solve_func.h"
#include "my_printf.h"
#include "print_errors.h"

/*!
 * @brief вспомогательная функция для myAssert, выводящая строчки в которых условие не выполнилось
 *
 * @param file название файл с ошибкой
 * @param func название функции с ошибкой
 * @param line_number номер строки с ошибкой
 */
void printErrorLines(const char * file, const char * func, size_t line_number) {
  colorPrintf(RED, BOLD, "file: %s\nfunc: %s\nline: %zu\n", file, func, line_number);

  char line[MAX_LINE] = {};
  FILE * fp = fopen(file, "r");

  for (size_t i = 0; i <= line_number; i++) {
    fgets(line, MAX_LINE, fp);
    if (i >= line_number - 2)
      colorPrintf(RED, BOLD, "%s", line);
  }

  fclose(fp);
  // abort(); TODO: как-нибудь по-доброму, без аборта
}

/*!
 * @brief функция, обрабатывающая ошибки
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
    case NULL_POINTER_FAILURE:
      colorPrintf(RED, PRIMARY, "Нулевой указатель.");
      break;
    default:
      colorPrintf(RED, PRIMARY, "Непредвиденная ошибка.");
      break;
  }
}
