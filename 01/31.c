#include "base.h"

/**
 * y = 2 * x / (3 - 5 * x^3)
 * x = -0.5
 */

double CALL(task)(double x, double eps, bool *divergent) {
    /* TODO: Реализовать */
    return 2 * x / (3 - 5 * pow(x, 3));
}

double CALL(base)(double x, double _) {
    return 2 * x / (3 - 5 * pow(x, 3));
}

double CALL(initiate_x)() {
    return -0.5;
}
