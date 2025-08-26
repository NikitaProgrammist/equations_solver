// unit_tests.cpp -- тестирование функции нахождения корней

#ifdef TEST
#include <stdio.h>

#include "solve_func.h"
#include "unit_tests.h"
#include "my_printf.h"

/*!
 * @brief функция тестирующая функцию решения уравнений
 *
 */
void testFindRootsEquation() {
  SquareEquations test_square_equations[] = { {.a = 0, .b = 0, .c = 0,
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
                                              .count_root = ONE_ROOT, .x1 = -1, .x2 = -1},
                                              {.a = 1, .b = -2, .c = 1,
                                              .count_root = ONE_ROOT, .x1 = 1, .x2 = 1},
                                              {.a = 1, .b = 1, .c = 213,
                                              .count_root = NO_ROOT, .x1 = 0, .x2 = 0} };

  const size_t test_count = sizeof(test_square_equations) / sizeof(test_square_equations[0]);
  for (size_t i = 0; i < test_count; i++) test(test_square_equations[i]);
}

/*!
 * @brief функция для тестирования из файла
 *
 * @param filename имя файла
 */
void fileTest(const char * filename) {
  size_t count = 0;
  CountRoots count_root = NO_ROOT;
  double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
  const int MAX_TESTS = 50;
  SquareEquations tests[MAX_TESTS] = {};
  FILE * fp = fopen(filename, "r");
  while (fscanf(fp, "%lf%lf%lf%d%lf%lf", &a, &b, &c, &count_root, &x1, &x2) == 6 && (count < MAX_TESTS)) {
    tests[count].a = a;
    tests[count].b = b;
    tests[count].c = c;
    tests[count].count_root = count_root;
    tests[count].x1 = x1;
    tests[count].x2 = x2;
    count++;
  }
  fclose(fp);
  for (size_t i = 0; i < count; i++) test(tests[i]);
}

/*!
 * @brief вспомогательная функция для тестирования уравнений
 *
 * @param test_square_equation структура уравнения
 */
void test(SquareEquations test_square_equation) {
  double a = test_square_equation.a;
  double b = test_square_equation.b;
  double c = test_square_equation.c;
  SquareEquations square_equation = {a, b, c};
  findRootsEquation(&square_equation);
  if (!(square_equation.count_root == test_square_equation.count_root &&
        compareDoubles(square_equation.x1 - test_square_equation.x1) &&
        compareDoubles(square_equation.x2 - test_square_equation.x2)))
    colorPrintf(RED, PRIMARY, "Тест %lf %lf %lf упал с ошибкой.", a, b, c);
}
#endif // TEST
