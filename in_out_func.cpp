#include <stdio.h>
#include <math.h>
#include "func_for_equations.h"

enum Errors inp(double *a, double *b, double *c) {
  if (a == NULL || b == NULL || c == NULL) return NULL_POINTER_FAILURE;
  printf("Введите коэффициенты a, b, c квадратного уравнения:\n");
  int input = scanf("%lf%lf%lf", a, b, c);
  if (input != 3) {
    return NUMBER_ROOTS_ERROR;
  }
  return SUCCESS;
}

enum Errors printRootsEquation(struct SquareEquations * square_equation) {
  if (square_equation == NULL) return NULL_POINTER_FAILURE;
  enum CountRoots count = square_equation->count_root;
  switch (count) {
    case INF_ROOT:
      printf("Уравнение имеет бесконечно много корней.\n");
      break;
    case NO_ROOT:
      printf("Уравнение не имеет решений.\n");
      break;
    case ONE_ROOT:
      printf("Уравнение имеет один корень: %lf.\n", square_equation->x1);
      break;
    case TWO_ROOT:
      printf("Уравнение имеет два корня: %lf, %lf.\n", square_equation->x1, square_equation->x2);
      break;
    default:
      return UNKNOWN_NUMBER_OF_ROOTS;
  }
  return SUCCESS;
}

void errorsParser(enum Errors error) {
  switch (error) {
    case SUCCESS:
      break;
    case UNKNOWN_NUMBER_OF_ROOTS:
      printf("Некорректное количество корней.");
      break;
    case NULL_POINTER_FAILURE:
      printf("Нулевой указатель.");
      break;
    default:
      printf("Непредвиденная ошибка.");
      break;
  }
}
