// func_for_equations.h -- файл констант и объявлений структур и функций для main.cpp

#ifndef FUNC_FOR_EQUATIONS_H

#define FUNC_FOR_EQUATIONS_H

#define EPS 0.000001

enum CountRoots {
  INF_ROOT=-1,
  NO_ROOT,
  ONE_ROOT,
  TWO_ROOT
};

enum Colors {
  BLACK=30,
  RED,
  GREEN,
  YELLOW,
  CYAN,
  PURPLE,
  BLUE,
  WHITE,
};

enum Fonts {
  BOLD=1,
  FAINT,
  ITALIC,
  UNDERLINE,
  CROSSED=9,
  PRIMARY
};

enum Errors {
  SUCCESS,
  EXIT,
  CONTINUE,
  UNKNOWN_NUMBER_OF_ROOTS,
  NULL_POINTER_FAILURE
};

struct SquareEquations {
  double a, b, c;
  enum CountRoots count_root;
  double x1, x2;
};

void parseConsoleArg(int argc, char ** argv);
void color_printf(enum Colors color, enum Fonts font, const char *fmt, ...);
void testFindRootsEquation();
void mainCycle(struct SquareEquations * square_equation);
void test(struct SquareEquations test_square_equation);
enum Errors inputCoeff(double * a, double * b, double * c);
enum Errors inputParse();
enum Errors findRootsEquation(struct SquareEquations * square_equation);
enum Errors findRootsLinearEquation(struct SquareEquations * square_equation);
enum Errors findRootsSquareEquation(struct SquareEquations * square_equation);
bool compareDoubles(double number);
enum Errors printRootsEquation(struct SquareEquations * square_equation);
void errorsParser(enum Errors error);

#endif
