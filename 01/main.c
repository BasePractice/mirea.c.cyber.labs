#include <stdlib.h>
#include <stdio.h>
#include "base.h"

double CALL(task)(double x, double eps);
double CALL(base)(double x, double eps);
double CALL(initiate_x)();

int
main(int argc, char *argv[]) {
    double x;
    double eps = EPS;
    double calculated;

    if (argc > 1) {
        x = strtod(argv[1], 0);
        if (argc > 2) {
            eps = strtod(argv[2], 0);
        }
    } else {
        x = CALL(initiate_x)();
    }
    fprintf(stdout, "Задание               : %s\n", STR(TASK));
    fprintf(stdout, "Начальное значение X  : %f\n", x);
    calculated = CALL(task)(x, eps);
    fprintf(stdout, "Результат самописный  : %f\n", calculated);
    calculated = CALL(base)(x, eps);
    fprintf(stdout, "Результат библиотечный: %f\n", calculated);
    return EXIT_SUCCESS;
}
