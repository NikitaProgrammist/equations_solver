// func_for_equations.h -- ���� �������� � ���������� �������� � ������� ��� main.cpp

#define EPS 0.000001

struct square_equations {
  double a, b, c;
  int count_roots;
  double x1, x2;
};

void find_roots_square_equation(struct square_equations * square_equation);
void print_roots_square_equation(struct square_equations * square_equation);
