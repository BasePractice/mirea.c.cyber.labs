#include "base.h"

/**
 * y = sin(x^3/2) + x
 * x = 1
 */

double CALL(task)(double x, double eps) {
    return x * eps;
}

double CALL(base)(double x, double eps) {
    return x * eps;
}

double CALL(initiate_x)() {
    return 1;
}