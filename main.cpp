// main.cpp -- программа для нахождения корней квадратного уравнения

#include <stdio.h>
#include <math.h>
#include "func_for_equations.h"

int main() {
  struct SquareEquations square_equation = {};
  enum Errors result = SUCCESS;
  char test_input = 'q';
  printf("Для завершения программы нажмите q.\n");
  while (true) {
    result = inp(&square_equation.a, &square_equation.b, &square_equation.c);
    if (result == NUMBER_ROOTS_ERROR) {
      test_input = getchar();
      if (test_input == 'q') {
        break;
      }
      printf("Некорректный ввод.\n");
    }
    else {
      errorsParser(result);
      result = findRootsEquation(&square_equation);
      errorsParser(result);
      result = printRootsEquation(&square_equation);
      errorsParser(result);
    }
    while ((test_input = getchar()) != '\n');
  }
  printf("Программа завершена корректно.\n");
  return 0;
}
