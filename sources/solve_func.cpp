// func_for_equations.cpp -- функции для решения уравнений

#include <stdio.h>
#include <math.h>

#include "solve_func.h"
#include "print_errors.h"
#include "my_printf.h"

/*!
 * @brief функция поиска корней уравнения
 *
 * @param square_equation структура уравнения
 * @return Errors возвращает ошибки, возникающие в процессе выполнения
 */
Errors findRootsEquation(SquareEquations * square_equation) {
  myAssert(isfinite(square_equation->a));
  myAssert(isfinite(square_equation->b));
  myAssert(isfinite(square_equation->c));
  myAssert(square_equation != NULL);

  if (compareDoubles(square_equation->a)) {
    return findRootsLinearEquation(square_equation);
  }
  else {
    return findRootsSquareEquation(square_equation);
  }
  return SUCCESS;
}

/*!
 * @brief функция поиска корня линейного уравнения
 *
 * @param square_equation структура квадратного уравнения
 * @return Errors возвращает ошибки, возникающие в процессе выполнения
 */
Errors findRootsLinearEquation(SquareEquations * square_equation) {
  myAssert(square_equation != NULL);

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
    myAssert(isfinite(-c / b));
    square_equation->x1 = -c / b;
  }
  return SUCCESS;
}

/*!
 * @brief функция поиска корней квадратного уравнения
 *
 * @param square_equation структура квадратного уравнения
 * @return Errors возвращает ошибки, возникающие в процессе выполнения
 */
Errors findRootsSquareEquation(SquareEquations * square_equation) {
  myAssert(square_equation != NULL);

  double a = square_equation->a;
  double b = square_equation->b;
  double c = square_equation->c;

  double d = b * b - 4 * a * c;
  myAssert(isfinite(d));

  if (compareDoubles(d)) {
    square_equation->count_root = ONE_ROOT;

    myAssert(isfinite(-b / (2 * a)));

    square_equation->x1 = square_equation->x2 = -b / (2 * a);
  }
  else if (d < 0) {
    square_equation->count_root = NO_ROOT;
  }
  else {
    square_equation->count_root = TWO_ROOT;

    double x1 = (-b + sqrt(d)) / (2 * a);
    double x2 = (-b - sqrt(d)) / (2 * a);

    myAssert(isfinite(x1));
    myAssert(isfinite(x2));

    if (x1 > x2) {
      square_equation->x1 = x1;
      square_equation->x2 = x2;
    }
    else {
      square_equation->x1 = x2;
      square_equation->x2 = x1;
    }
  }
  return SUCCESS;
}

/*!
 * @brief Сравнение double с нулем
 *
 * @param number число
 * @return true
 * @return false
 */
bool compareDoubles(double number) {
  const double EPS = 1e-6;
  if (fabs(number) < EPS)
    return true;
  return false;
}
