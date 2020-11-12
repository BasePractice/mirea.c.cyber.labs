#include "base.h"

/**
 * y = x * ch(x / 2) + x
 * x = -1
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x * x_chn(x / 2, eps, divergent) + x;
}

double CALL(base)(double x, double _) {
    return x * cosh(x / 2) + x;
}

double CALL(initiate_x)() {
    return -1;
}
