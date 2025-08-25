// solve_func.h заголовочный файл для solve_func.cpp

#ifndef SOLVE_FUNC_H
#define SOLVE_FUNC_H

#define EPS 1e-6 // константа в функции, где используется
#define MAX_LINE 150 // константа

enum Errors {
  SUCCESS,
  EXIT,
  CONTINUE,
  ASSERT_FAILED,
  UNKNOWN_NUMBER_OF_ROOTS,
  NULL_POINTER_FAILURE
};

enum CountRoots {
  INF_ROOT=-1,
  NO_ROOT,
  ONE_ROOT,
  TWO_ROOT
};

struct SquareEquations {
  double a, b, c;
  enum CountRoots count_root;
  double x1, x2;
};

Errors findRootsEquation(SquareEquations * square_equation);
Errors findRootsLinearEquation(SquareEquations * square_equation);
Errors findRootsSquareEquation(SquareEquations * square_equation);
bool compareDoubles(double number);

#endif // SOLVE_FUNC_H
