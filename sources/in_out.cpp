// in_out.cpp -- функции для обработки ввода и вывода

#include <stdio.h>
#include <string.h>

#include "solve.h"
#include "unit_tests.h"
#include "my_printf.h"
#include "in_out.h"
#include "print_errors.h"

/*!
 * @brief обработка консольных аргументов
 *
 * @param argc количество аргументов
 * @param argv аргументы
 */
void parseConsoleArg(int argc, char * argv[]) {
  if (argc > 1) {
    if (!strcmp(argv[1], "--help")) {
      printf("Допустимые консольные команды:\n--embedded-test (при TEST_FLAGS=ON) - "
      "запуск программы с предварительным тестированием.\n"
      "--file-test (при TEST_FLAGS=ON) - запуск программы с предварительным тестированием из файла.\n"
      "--base - запуск без предварительного тестирования.\n--version - печатает версию программы.\n");
    }

    #ifdef TEST
    else if  (!strcmp(argv[1], "--embedded-test")) {
      printf("Программа была запущена с предварительным тестированием.\n");
      testFindRootsEquation();
    }
    else if (!strcmp(argv[1], "--file-test")) {
      printf("Программа была запущена с предварительным тестированием из файла.\n");
      fileTest("../tests/test1.txt");
    }
    else if (!strcmp(argv[1], "--base")) {
      printf("Программа была запущена без предварительного тестирования.\n");
    }
    #endif // TEST

    else if (!strcmp(argv[1], "--version")) {
      printf("Equation solver version 3.0.\n");
    }
    else {
      printf("Запустите код с командой --help для получения информации о всех допустимых командах.\n");
    }
  }
}

/*!
 * @brief ввод коэффициентов уравнения
 *
 * @param square_equation структура уравнения
 * @return Errors возвращает ошибки, возникающие в процессе выполнения
 */
Errors inputCoeff(SquareEquations * square_equation) {
  myAssert(square_equation != NULL);

  colorPrintf(GREEN, PRIMARY, "Введите коэффициенты a, b, c квадратного уравнения:");

  int input = scanf("%lf%lf%lf", &(square_equation->a), &(square_equation->b), &(square_equation->c));
  if (input != 3) {
    return inputParse();
  }

  return SUCCESS;
}

/*!
 * @brief обработка некорректного ввода
 *
 * @return Errors возвращает ошибки, возникающие в процессе выполнения
 */
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

/*!
 * @brief вывод решений уравнения
 *
 * @param square_equation структура уравнения
 * @return Errors возвращает ошибки, возникающие в процессе выполнения
 */
Errors printRootsEquation(SquareEquations * square_equation) {
  myAssert(square_equation != NULL);

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
