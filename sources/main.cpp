// main.cpp -- программа для нахождения корней квадратного уравнения

#include <stdio.h>
#include "func_for_equations.h"

int main() {
  testFindRootsEquation();
  struct SquareEquations square_equation = {};
  mainCycle(&square_equation);
  color_printf(GREEN, PRIMARY, "Программа завершена корректно.\n");
  return 0;
}

// color_printf(GREEN, BOLD, "hjkdsjAHADSK %d %s %lg", 1, "gfgdfgd", 27.5);
// variadic args
// vprintf

void mainCycle(struct SquareEquations * square_equation) {
  int clear_buf = ' ';
  color_printf(GREEN, PRIMARY, "Для завершения программы нажмите q.");
  enum Errors result = SUCCESS;
  while (true) {
    result = inputCoeff(&(square_equation->a), &(square_equation->b), &(square_equation->c));
    if (result == EXIT) break;
    else if (result == CONTINUE) continue;
    result = findRootsEquation(square_equation);
    errorsParser(result);
    result = printRootsEquation(square_equation);
    errorsParser(result);
    while ((clear_buf = getchar()) != '\n');
  }
}
