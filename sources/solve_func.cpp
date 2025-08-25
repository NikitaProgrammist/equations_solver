// func_for_equations.cpp -- функции для решения уравнений

#include <stdio.h>
#include <math.h>

#include "solve_func.h"
#include "print_errors.h"
#include "my_printf.h"

Errors findRootsEquation(SquareEquations * square_equation) {
  myAssert(std::isfinite(square_equation->a));
  myAssert(std::isfinite(square_equation->b));
  myAssert(std::isfinite(square_equation->c));
  if (square_equation == NULL) {
    return NULL_POINTER_FAILURE;
  }
  if (compareDoubles(square_equation->a)) {
    return findRootsLinearEquation(square_equation);
  }
  else {
    return findRootsSquareEquation(square_equation);
  }
  return SUCCESS;
}

enum Errors findRootsLinearEquation(struct SquareEquations * square_equation) {
  if (square_equation == NULL) {
    return NULL_POINTER_FAILURE;
  }
  double b = square_equation->b;
  double c = square_equation->c;
  if (compareDoubles(b)) {
    if (compareDoubles(c)) {
      square_equation->count_root = INF_ROOT;
    }
    else {
    square_equation->count_root = NO_ROOT;
    }
  }
  else {
    square_equation->count_root = ONE_ROOT;
    myAssert(std::isfinite(-c / b));
    square_equation->x1 = -c / b;
  }
  return SUCCESS;
}

Errors findRootsSquareEquation(SquareEquations * square_equation) {
  if (square_equation == NULL) {
    return NULL_POINTER_FAILURE;
  }
  double a = square_equation->a;
  double b = square_equation->b;
  double c = square_equation->c;

  double d = b * b - 4 * a * c;
  myAssert(std::isfinite(d));

  if (compareDoubles(d)) {
    square_equation->count_root = ONE_ROOT;
    myAssert(std::isfinite(-b / (2 * a)));
    square_equation->x1 = -b / (2 * a);
  }
  else if (d < 0) {
    square_equation->count_root = NO_ROOT;
  }
  else {
    square_equation->count_root = TWO_ROOT;
    myAssert(std::isfinite((-b + sqrt(d)) / (2 * a)));
    myAssert(std::isfinite((-b - sqrt(d)) / (2 * a)));
    square_equation->x1 = (-b + sqrt(d)) / (2 * a);
    square_equation->x2 = (-b - sqrt(d)) / (2 * a);
  }
  return SUCCESS;
}

bool compareDoubles(double number) {
  if (fabs(number) < EPS)
    return true;
  return false;
}
