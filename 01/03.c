#include "base.h"

/**
 * y = exp(-(x/7)) + x + 1
 * x = 1
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_exp(-(x / 7), eps, divergent) + x + 1;
}

double CALL(base)(double x, double _) {
    return exp(-(x / 7)) + x + 1;
}

double CALL(initiate_x)() {
    return 1;
}
