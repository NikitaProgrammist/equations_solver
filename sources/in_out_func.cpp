// in_out_func.cpp -- функции для вывода решений

#include <stdio.h>
#include <string.h>

#include "solve_func.h"
#include "unit_tests.h"
#include "my_printf.h"
#include "in_out_func.h"

void parseConsoleArg(int argc, char ** argv) { // TODO: вспомнить, что предпочитает здесь видеть дед
  if (argc > 1) { // TODO: size_t
    if (!strcmp(argv[1], "--help")) { // TODO: даже если можно без скобок if, то лучше с ними
      printf("Допустимые консольные команды:\n--test - запуск программы с предварительным тестированием.\n"
      "--base - запуск без предварительного тестирования.\n--version - печатает версию программы.\n");
    }
    else if  (!strcmp(argv[1], "--test")) {
      printf("Программа была запущена с предварительным тестированием.\n");
      testFindRootsEquation();
    }
    else if (!strcmp(argv[1], "--base")) {
      printf("Программа была запущена без предварительного тестирования.\n");
    }
    else if (!strcmp(argv[1], "--version")) {
      printf("Equation solver version 3.0.\n");
    }
    else {
      printf("Запустите код с командой --help для получения информации о всех допустимых командах.\n");
    }
  }
}

Errors inputCoeff(SquareEquations * square_equation) { // TODO передать структуру
  if (square_equation == NULL) {
    return NULL_POINTER_FAILURE;
  }
  colorPrintf(GREEN, PRIMARY, "Введите коэффициенты a, b, c квадратного уравнения:");
  int input = scanf("%lf%lf%lf", &(square_equation->a), &(square_equation->b), &(square_equation->c));
  if (input != 3) { // TODO: ассерты в функциях на std::isfinite
    return inputParse();
  }
  return SUCCESS;
}

Errors inputParse() {
  int test_input = getchar();
  if (test_input == 'q') {
    return EXIT;
  }
  if (test_input == '\n') {
    colorPrintf(RED, PRIMARY, "Некорректный ввод.");
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
  colorPrintf(RED, PRIMARY, "Некорректный ввод.");
  return CONTINUE;
}

Errors printRootsEquation(SquareEquations * square_equation) {
  if (square_equation == NULL) {
    return NULL_POINTER_FAILURE;
  }

  CountRoots count = square_equation->count_root;

  switch (count) {
    case INF_ROOT:
      colorPrintf(RED, PRIMARY, "Уравнение имеет бесконечно много корней.");
      break;
    case NO_ROOT:
      colorPrintf(RED, PRIMARY, "Уравнение не имеет решений.");
      break;
    case ONE_ROOT:
      colorPrintf(GREEN, PRIMARY, "Уравнение имеет один корень: %lf.", square_equation->x1);
      break;
    case TWO_ROOT:
      colorPrintf(GREEN, PRIMARY, "Уравнение имеет два корня: %lf, %lf.", square_equation->x1, square_equation->x2);
      break;
    default:
      return UNKNOWN_NUMBER_OF_ROOTS;
  }

  return SUCCESS;
}
