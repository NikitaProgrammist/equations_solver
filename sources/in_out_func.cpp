// in_out_func.cpp -- функции для вывода решений

#include <stdio.h>
#include "func_for_equations.h"

enum Errors inputCoeff(double *a, double *b, double *c) {
  if (a == NULL || b == NULL || c == NULL) return NULL_POINTER_FAILURE;
  color_printf(GREEN, PRIMARY, "Введите коэффициенты a, b, c квадратного уравнения:");
  int input = scanf("%lf%lf%lf", a, b, c);
  if (input != 3 || (*a != *a) || (*b != *b) || (*c != *c)) {
    return inputParse();
  }
  return SUCCESS;
}

enum Errors inputParse() {
  int test_input = getchar();
  if (test_input == 'q') {
    return EXIT;
  }
  if (test_input == '\n') {
    color_printf(RED, PRIMARY, "Некорректный ввод.");
    return CONTINUE;
  }
  if (test_input == EOF) {
    printf("\n");
    return EXIT;
  }
  while ((test_input = getchar()) != '\n') {
    if (test_input == EOF) {
      printf("\n");
      return EXIT;
    }
  }
  color_printf(RED, PRIMARY, "Некорректный ввод.");
  return CONTINUE;
}

enum Errors printRootsEquation(struct SquareEquations * square_equation) {
  if (square_equation == NULL) return NULL_POINTER_FAILURE;
  enum CountRoots count = square_equation->count_root;
  switch (count) {
    case INF_ROOT:
      color_printf(RED, PRIMARY, "Уравнение имеет бесконечно много корней.");
      break;
    case NO_ROOT:
      color_printf(RED, PRIMARY, "Уравнение не имеет решений.");
      break;
    case ONE_ROOT:
      color_printf(GREEN, PRIMARY, "Уравнение имеет один корень: %lf.", square_equation->x1);
      break;
    case TWO_ROOT:
      color_printf(GREEN, PRIMARY, "Уравнение имеет два корня: %lf, %lf.", square_equation->x1, square_equation->x2);
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
      color_printf(RED, PRIMARY, "Некорректное количество корней.");
      break;
    case NULL_POINTER_FAILURE:
      color_printf(RED, PRIMARY, "Нулевой указатель.");
      break;
    default:
      color_printf(RED, PRIMARY, "Непредвиденная ошибка.");
      break;
  }
}
