// main.cpp -- программа для нахождения корней квадратного уравнения

#include <stdio.h>
#include "solve_func.h"
#include "in_out_func.h"
#include "my_printf.h"


void mainCycle(struct SquareEquations * square_equation);

int main(int argc, char ** argv) {
  parseConsoleArg(argc, argv);
  struct SquareEquations square_equation = {};
  mainCycle(&square_equation);
  colorPrintf(GREEN, PRIMARY, "Программа завершена корректно.");
  return 0;
}

void mainCycle(struct SquareEquations * square_equation) {
  int clear_buf = ' ';
  colorPrintf(GREEN, PRIMARY, "Для завершения программы нажмите q.");
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
