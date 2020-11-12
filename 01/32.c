#include "base.h"

/**
 * y = sh(2 * x^6) + x
 * x = -0.9
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_shn(2 * pow(x, 6), eps, divergent) + x;
}

double CALL(base)(double x, double _) {
    return sinh(2 * pow(x, 6)) + x;
}

double CALL(initiate_x)() {
    return -0.9;
}
