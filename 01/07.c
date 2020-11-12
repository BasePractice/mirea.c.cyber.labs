#include "base.h"

/**
 * y = ch(x / 2) + x - x^2
 * x = 1
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_chn(x / 2, eps, divergent) + x - pow(x, 2);
}

double CALL(base)(double x, double _) {
    return cosh(x / 2) + x - pow(x, 2);
}

double CALL(initiate_x)() {
    return 1;
}
