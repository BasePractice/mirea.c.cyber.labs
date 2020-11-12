#include "base.h"

/**
 * y = arctg(2 * x^2) + 3 * x - 1
 * x = -0.5
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_atg(2 * pow(x, 2), eps, divergent) + 3 * x - 1;
}

double CALL(base)(double x, double _) {
    return atan(2 * pow(x, 2)) + 3 * x - 1;
}

double CALL(initiate_x)() {
    return -0.5;
}
