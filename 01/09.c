#include "base.h"

/**
 * y = cos(x / 2) + x - 1
 * x = -1
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_cos(x / 2, eps, divergent) + x - 1;
}

double CALL(base)(double x, double _) {
    return cos(x / 2) + x - 1;
}

double CALL(initiate_x)() {
    return -1;
}
