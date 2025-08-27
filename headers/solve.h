// solve.h заголовочный файл для solve.cpp

#ifndef SOLVE_FUNC_H
#define SOLVE_FUNC_H

enum Errors {
  SUCCESS,
  EXIT,
  CONTINUE,
  FIND_EOF,
  ASSERT_FAILED,
  UNKNOWN_NUMBER_OF_ROOTS
};

enum CountRoots {
  INF_ROOT = -1,
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
