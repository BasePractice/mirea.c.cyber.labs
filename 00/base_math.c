#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "base_math.h"

#define DEFINE_TAYLOR_SERIES(expression)         \
    double sum = 0, current = x;                 \
    int n = 0;                                   \
    while (fabs(current) > eps) {                \
        if (n > 1000) {                          \
            (*divergent) = true;                 \
            return sum;                          \
        }                                        \
        current = expression;                    \
        sum += current;                          \
        ++n;                                     \
    }                                            \
    return sum;

double x_fac(int n) {
    if (n == 0) {
        return 1;
    } else {
        return (n * x_fac(n - 1));
    }
}

double x_sin(double x, double eps, bool *divergent) {
    DEFINE_TAYLOR_SERIES((pow(-1, n) * pow(x, (2 * n) + 1)) / x_fac((2 * n) + 1))
}

double x_cos(double x, double eps, bool *divergent) {
    DEFINE_TAYLOR_SERIES((pow(-1, n) * pow(x, 2 * n)) / x_fac(2 * n))
}

double x_exp(double x, double eps, bool *divergent) {
    DEFINE_TAYLOR_SERIES(pow(x, n) / x_fac(n))
}

double x_shn(double x, double eps, bool *divergent) {
    DEFINE_TAYLOR_SERIES(pow(x, (2 * n) + 1) / x_fac((2 * n) + 1))
}

double x_chn(double x, double eps, bool *divergent) {
    DEFINE_TAYLOR_SERIES(pow(x, 2 * n) / x_fac(2 * n))
}

double x_atg(double x, double eps, bool *divergent) {
    DEFINE_TAYLOR_SERIES( pow(-1, n) * pow(x, 2 * n + 1) / (2 * n + 1) )
}

double x_lln(double x, double eps, bool *divergent) {
    x += 1;
    DEFINE_TAYLOR_SERIES((pow(-1, n + 1) * pow(x, n)) / n)
}


