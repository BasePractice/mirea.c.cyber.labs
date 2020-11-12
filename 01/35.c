#include "base.h"

/**
 * y = cos(2 * x / 3) + 2 * x - x^2
 * x = 1/4
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_cos(2 * x / 3, eps, divergent) + 2 * x - pow(x, 2);
}

double CALL(base)(double x, double _) {
    return cos(2 * x / 3) + 2 * x - pow(x, 2);
}

double CALL(initiate_x)() {
    return 1. / 4.;
}
