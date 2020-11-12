#include "base.h"

/**
 * y = sin(3 * x) - cos(x^2) - x + 1
 * x = 0.5
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_sin(3 * x, eps, divergent) - x_cos(pow(x, 2), eps, divergent) - x + 1;
}

double CALL(base)(double x, double _) {
    return sin(3 * x) - cos(pow(x, 2)) - x + 1;
}

double CALL(initiate_x)() {
    return 0.5;
}
