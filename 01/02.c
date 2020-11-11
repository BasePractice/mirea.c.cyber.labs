#include "base.h"

/**
 * y = cos(x/3) + x - x^2
 * x = -1
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
