// main.cpp -- программа для нахождения корней квадратного уравнения

#include <stdio.h>

#include "solve_func.h"
#include "in_out_func.h"
#include "my_printf.h"
#include "print_errors.h"

Errors mainCycle(SquareEquations * square_equation);

// сделать два режима тестов. Одни тесты из файла, другие (флаг --embedded-test) как обычно
// потом сделать под условную компиляцию. То есть я хочу, чтобы ты писал вот так: make TEST_FLAG=ON
// и тогда у тебя к сборке будет добавляться флаг -DTEST

int main(int argc, char * argv[]) {
  parseConsoleArg(argc, argv);
  SquareEquations square_equation = {};
  Errors result = mainCycle(&square_equation);
  errorsParser(result);
  colorPrintf(GREEN, PRIMARY, "Программа завершена корректно.");
  return 0;
}

/*!
 * @brief основной цикл программы
 *
 * @param square_equation структура уравнения
 * @return int возвращает корректность завершения своей работы
 */
Errors mainCycle(SquareEquations * square_equation) {
  myAssert(square_equation != NULL);
  int clear_buf = ' ';
  colorPrintf(GREEN, PRIMARY, "Для завершения программы нажмите q.");
  Errors result = SUCCESS;

  while (true) {
    result = inputCoeff(square_equation);

    if (result == EXIT) {
      break;
    }
    else if (result == CONTINUE) {
      continue;
    }

    while ((clear_buf = getchar()) != '\n') {
      if (clear_buf == EOF) {
        printf("\n");
        return SUCCESS;
      }
    }

    result = findRootsEquation(square_equation);
    errorsParser(result);

    if (result == SUCCESS) {
      result = printRootsEquation(square_equation);
      errorsParser(result);
    }
  }
  return SUCCESS;
}
