// in_out_func.h -- заголовочный файл для in_out_func.cpp

#ifndef IN_OUT_FUNC_H

#define IN_OUT_FUNC_H

void parseConsoleArg(int argc, char ** argv);
enum Errors inputCoeff(double * a, double * b, double * c);
enum Errors inputParse();
enum Errors printRootsEquation(struct SquareEquations * square_equation);

#endif
