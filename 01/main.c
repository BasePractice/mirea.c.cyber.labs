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
    double custom;

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
    fprintf(stdout, "Приближение EPS       : %f\n", eps);
    custom = CALL(task)(x, eps);
    fprintf(stdout, "Результат самописный  : %f\n", custom);
    double system = CALL(base)(x, eps);
    fprintf(stdout, "Результат библиотечный: %f\n", system);
    fprintf(stdout, "Результат сравнения   : %s\n", fabs(custom - system) >= eps ? "PASSED" : "FAILED");
    return EXIT_SUCCESS;
}
