// main.cpp -- программа для нахождения корней квадратного уравнения

#include <stdio.h>

#include "solve_func.h"
#include "in_out_func.h"
#include "my_printf.h"
#include "print_errors.h"

Errors mainCycle(SquareEquations * square_equation);
void skipLine();

int main(int argc, char * argv[]) {
  parseConsoleArg(argc, argv);
  SquareEquations square_equation = {};
  Errors result = mainCycle(&square_equation);
  errorsParser(result);
  colorPrintf(GREEN, PRIMARY, "Программа завершена корректно.");
  return 0;
}

/*!
 * @brief основной цикл программы
 *
 * @param square_equation структура уравнения
 * @return int возвращает корректность завершения своей работы
 */
Errors mainCycle(SquareEquations * square_equation) {
  myAssert(square_equation != NULL);
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

    skipLine();

    result = findRootsEquation(square_equation);
    errorsParser(result);

    if (result == SUCCESS) {
      result = printRootsEquation(square_equation);
      errorsParser(result);
    }
  }
  return SUCCESS;
}

void skipLine() {
  int skip = ' ';
  while ((skip = getchar()) != '\n') {
    if (skip == EOF) {
      printf("\n");
      return SUCCESS;
    }
  }
}
