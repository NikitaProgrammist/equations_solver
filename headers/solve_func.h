// solve_func.h заголовочный файл для solve_func.cpp

#ifndef SOLVE_FUNC_H

#define SOLVE_FUNC_H

#define EPS 0.000001

enum Errors {
  SUCCESS,
  EXIT,
  CONTINUE,
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

enum Errors findRootsEquation(struct SquareEquations * square_equation);
enum Errors findRootsLinearEquation(struct SquareEquations * square_equation);
enum Errors findRootsSquareEquation(struct SquareEquations * square_equation);
bool compareDoubles(double number);

#endif
