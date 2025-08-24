// unit_tests.cpp -- тестирование функции нахождения корней

#include <stdio.h>
#include "solve_func.h"
#include "my_printf.h"
#include "unit_tests.h"

void testFindRootsEquation() {
  const int test_count = 9;
  struct SquareEquations test_square_equations[test_count] = {{.a = 0, .b = 0, .c = 0,
                                                              .count_root = INF_ROOT, .x1 = 0, .x2 = 0},
                                                             {.a = 0, .b = 0, .c = 1,
                                                              .count_root = NO_ROOT, .x1 = 0, .x2 = 0},
                                                             {.a = 0, .b = 1, .c = 0,
                                                              .count_root = ONE_ROOT, .x1 = 0, .x2 = 0},
                                                             {.a = 1, .b = 0, .c = 0,
                                                              .count_root = ONE_ROOT, .x1 = 0, .x2 = 0},
                                                             {.a = 1, .b = 1, .c = 0,
                                                              .count_root = TWO_ROOT, .x1 = 0, .x2 = -1},
                                                             {.a = 0, .b = 1, .c = 1,
                                                              .count_root = ONE_ROOT, .x1 = -1, .x2 = 0},
                                                             {.a = 1, .b = 2, .c = 1,
                                                              .count_root = ONE_ROOT, .x1 = -1, .x2 = 0},
                                                             {.a = 1, .b = -2, .c = 1,
                                                              .count_root = ONE_ROOT, .x1 = 1, .x2 = 0},
                                                             {.a = 1, .b = 1, .c = 213,
                                                              .count_root = NO_ROOT, .x1 = 0, .x2 = 0}};
  for (int i = 0; i < test_count; i++) test(test_square_equations[i]);
}

void test(struct SquareEquations test_square_equation) {
  double a = test_square_equation.a;
  double b = test_square_equation.b;
  double c = test_square_equation.c;
  struct SquareEquations square_equation = {a, b, c};
  findRootsEquation(&square_equation);
  if (!(square_equation.count_root == test_square_equation.count_root &&
        compareDoubles(square_equation.x1 - test_square_equation.x1) &&
        compareDoubles(square_equation.x2 - test_square_equation.x2)))
    colorPrintf(RED, PRIMARY, "Тест %lf %lf %lf упал с ошибкой.", a, b, c);
}
