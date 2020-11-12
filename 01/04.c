#include "base.h"

/**
 * y = arctg(3 * x) - x
 * x = -0.5
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_atg(3 * x, eps, divergent) - x;
}

double CALL(base)(double x, double _) {
    return atan(3 * x) - x;
}

double CALL(initiate_x)() {
    return -0.5;
}
