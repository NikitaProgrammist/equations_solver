// func_for_equations.h -- файл констант и объявлений структур и функций для main.cpp

#ifndef _FUNC_FOR_EQUATIONS_H

#define _FUNC_FOR_EQUATIONS_H

#define EPS 0.000001

enum CountRoots {
  INF_ROOT=-1,
  NO_ROOT,
  ONE_ROOT,
  TWO_ROOT
};

enum Errors {
  SUCCESS,
  NUMBER_ROOTS_ERROR,
  UNKNOWN_NUMBER_OF_ROOTS,
  NULL_POINTER_FAILURE
};

struct SquareEquations {
  double a, b, c;
  enum CountRoots count_root;
  double x1, x2;
};

enum Errors inp(double * a, double * b, double * c);
enum Errors findRootsEquation(struct SquareEquations * square_equation);
enum Errors findRootsLinearEquation(struct SquareEquations * square_equation);
enum Errors findRootsSquareEquation(struct SquareEquations * square_equation);
bool compareDoubles(double a, double b);
enum Errors printRootsEquation(struct SquareEquations * square_equation);
void errorsParser(enum Errors error);

#endif
