// print_errors.h -- заголовочный файл для print_errors.cpp

#ifndef PRINT_ERRORS_H
#define PRINT_ERRORS_H

#define myAssert(arg) {                                                        \
    if (!(arg)) {                                                              \
        colorPrintf(RED, BOLD, "\nAssertion failed: " #arg "\n");              \
        printErrorLines("../" __FILE__, __PRETTY_FUNCTION__, __LINE__);        \
        return ASSERT_FAILED;                                                  \
    }                                                                          \
}

void printErrorLines(const char * file, const char * func, size_t line_number);
void errorsParser(Errors error);

#endif // PRINT_ERRORS_H
