#include "base.h"

/**
 * y = ch(2 * x) + x
 * x = 1
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_chn(2 * x, eps, divergent) + x;
}

double CALL(base)(double x, double _) {
    return cosh(2 * x) + x;
}

double CALL(initiate_x)() {
    return 1;
}
