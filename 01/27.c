#include "base.h"

/**
 * y = sin(2 * x^3) - 2 * x
 * x = -0.5
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_sin(2 * pow(x, 3), eps, divergent) - 2 * x;
}

double CALL(base)(double x, double _) {
    return sin(2 * pow(x, 3)) - 2 * x;
}

double CALL(initiate_x)() {
    return -0.5;
}
