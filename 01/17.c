#include "base.h"

/**
 * y = sin (3 * x^2 / 2) - x
 * x = 0.5
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_sin(3 * pow(x, 2) / 2, eps, divergent) - x;
}

double CALL(base)(double x, double _) {
    return sin(3 * pow(x, 2) / 2) - x;
}

double CALL(initiate_x)() {
    return 0.5;
}
