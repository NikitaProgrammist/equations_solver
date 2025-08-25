// main.cpp -- программа для нахождения корней квадратного уравнения

#include <stdio.h>

#include "solve_func.h"
#include "in_out_func.h"
#include "my_printf.h"
#include "print_errors.h"

int mainCycle(SquareEquations * square_equation);

int main(int argc, char ** argv) {
  parseConsoleArg(argc, argv);
  SquareEquations square_equation = {};
  mainCycle(&square_equation);
  colorPrintf(GREEN, PRIMARY, "Программа завершена корректно.");
  return 0;
}

/*!
 * @brief основной цикл программы
 *
 * @param square_equation структура уравнения
 * @return int возвращает корректность завершения своей работы
 */
int mainCycle(SquareEquations * square_equation) {
  int clear_buf = ' ';
  colorPrintf(GREEN, PRIMARY, "Для завершения программы нажмите q.");
  Errors result = SUCCESS;

  while (true) {
    result = inputCoeff(square_equation);

    if (result == EXIT) {
      break;
    }
    else if (result == CONTINUE) {
      continue;
    }

    while ((clear_buf = getchar()) != '\n') {
      if (clear_buf == EOF) {
        printf("\n");
        return 1;
      }
    }

    result = findRootsEquation(square_equation);
    errorsParser(result);

    if (result == SUCCESS) {
      result = printRootsEquation(square_equation);
      errorsParser(result);
    }
  }
  return 0;
}
