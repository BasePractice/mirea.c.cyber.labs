#include "base.h"

/**
 * y = x * sin(2 * x) - 1
 * x = -1
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x * x_sin(2 * x, eps, divergent) - 1;
}

double CALL(base)(double x, double _) {
    return x * sin(2 * x) - 1;
}

double CALL(initiate_x)() {
    return -1;
}
