// func_for_equations.cpp -- функции для решения уравнений

#include <stdio.h>
#include <math.h>
#include "func_for_equations.h"

// прочитать про assert, попробовать придумать свой кастомный, попробовать добавить например для цветной печати и ошибок и корней
// чуть-чуть переделать сами ошибки и разобрать, что с ctrl+D и в принципе с EOF
// сделать функцию compare_doubles. И привести весь код к одному какому-то кодстайлу
// функции - mainCycle
// имя enum - ErrorsSquare, сами значание полностью капсом
// структуры - название также как у enum, сами переменные с маленькой буквы, как и все переменные, например square_solver

enum Errors findRootsEquation(struct SquareEquations * square_equation) {
  if (square_equation == NULL) return NULL_POINTER_FAILURE;
  double a = square_equation->a;
  double b = square_equation->b;
  double c = square_equation->c;
  if (compareDoubles(fabs(a), EPS)) {
    return findRootsLinearEquation(square_equation);
  }
  else {
    return findRootsSquareEquation(square_equation);
  }
  return SUCCESS;
}

enum Errors findRootsLinearEquation(struct SquareEquations * square_equation) {
  if (square_equation == NULL) return NULL_POINTER_FAILURE;
  double b = square_equation->b;
  double c = square_equation->c;
  if (compareDoubles(fabs(b), EPS)) {
    if (compareDoubles(fabs(c), EPS)) {
      square_equation->count_root = INF_ROOT;
    }
    else {
    square_equation->count_root = NO_ROOT;
    }
  }
  else {
    square_equation->count_root = ONE_ROOT;
    square_equation->x1 = -c / b;
  }
  return SUCCESS;
}

enum Errors findRootsSquareEquation(struct SquareEquations * square_equation) {
  if (square_equation == NULL) return NULL_POINTER_FAILURE;
  double a = square_equation->a;
  double b = square_equation->b;
  double c = square_equation->c;

  double d = b * b - 4 * a * c;

  if (compareDoubles(fabs(d), EPS)) {
    square_equation->count_root = ONE_ROOT;
    square_equation->x1 = -b / (2 * a);
  }
  else if (compareDoubles(d, 0)) {
    square_equation->count_root = NO_ROOT;
  }
  else {
    square_equation->count_root = TWO_ROOT;
    square_equation->x1 = (-b + sqrt(d)) / (2 * a);
    square_equation->x2 = (-b - sqrt(d)) / (2 * a);
  }
  return SUCCESS;
}

bool compareDoubles(double a, double b) {
  if (a < b)
    return true;
  return false;
}
