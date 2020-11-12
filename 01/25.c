#include "base.h"

/**
 * y = sin(x^3) - x
 * x = -0.5
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_sin(pow(x, 3), eps, divergent) - x;
}

double CALL(base)(double x, double _) {
    return sin(pow(x, 3)) - x;
}

double CALL(initiate_x)() {
    return -0.5;
}
