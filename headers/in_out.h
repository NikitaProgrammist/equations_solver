// in_out.h -- заголовочный файл для in_out.cpp

#ifndef IN_OUT_FUNC_H
#define IN_OUT_FUNC_H

void parseConsoleArg(int argc, char * argv[]);
Errors inputCoeff(SquareEquations * square_equation);
Errors inputParse();
Errors printRootsEquation(SquareEquations * square_equation);

#endif // IN_OUT_FUNC_H
