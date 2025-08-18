// func_for_equations.cpp -- функции для решения уравнений и вывода результата

#include <stdio.h>
#include "TXLib.h"
#include "func_for_equations.h"

void find_roots_square_equation(struct square_equations * square_equation) {
  double a = square_equation->a;
  double b = square_equation->b;
  double c = square_equation->c;

  double d = b * b - 4 * a * c;

  if (fabs(a) < EPS && fabs(b) < EPS && fabs(c) < EPS) {
    square_equation->count_roots = -1;
  }
  else if ((fabs(a) < EPS && fabs(b) < EPS) || (d < 0)) {
    square_equation->count_roots = 0;
  }
  else if (fabs(a) < EPS) {
    square_equation->count_roots = 1;
    square_equation->x1 = -c / b;
  }
  else if (fabs(d) < EPS) {
    square_equation->count_roots = 1;
    square_equation->x1 = -b / (2 * a);
  }
  else {
    square_equation->count_roots = 2;
    square_equation->x1 = (-b + sqrt(d)) / (2 * a);
    square_equation->x2 = (-b - sqrt(d)) / (2 * a);
  }
}

void print_roots_square_equation(struct square_equations * square_equation) {
  int count = square_equation->count_roots;
  switch (count) {
    case -1:
      printf("Уравнение имеет бесконечно много корней.");
      break;
    case 0:
      printf("Уравнение не имеет решений.");
      break;
    case 1:
      printf("Уравнение имеет один корень: %f.", square_equation->x1);
      break;
    default:
      printf("Уравнение имеет два корня: %f, %f.", square_equation->x1, square_equation->x2);
      break;
  }
}
