// print_errors.h -- заголовочный файл для print_errors.cpp

#ifndef PRINT_ERRORS_H

#define PRINT_ERRORS_H

#define myAssert(arg) if (!(arg)) { colorPrintf(RED, BOLD, "\nAssertion failed: " #arg "\n"); printErrorLines("../" __FILE__, __func__, __LINE__);}

void printErrorLines(const char * file, const char * func, long int line_number);
void errorsParser(enum Errors error);

#endif
