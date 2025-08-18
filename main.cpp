// main.cpp -- ��������� ��� ���������� ������ ����������� ���������

#include <stdio.h>
#include "TXLib.h"
#include "func_for_equations.h"

int main() {
  int input;
  struct square_equations square_equation = {};

  printf("������� ������������ a, b, c ����������� ���������:\n");
  input = scanf("%lf%lf%lf", &square_equation.a, &square_equation.b, &square_equation.c);
  if (input != 3) {
    printf("������������ ����.");
    exit(0);
  }
  printf("%lf %lf %lf", square_equation.a, square_equation.b, square_equation.c);
  find_roots_square_equation(&square_equation);
  print_roots_square_equation(&square_equation);
  return 0;
}
