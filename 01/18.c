#include "base.h"

/**
 * y = arctg(x^3)/x - x
 * x = -0.5
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_atg(pow(x, 3), eps, divergent) / x - x;
}

double CALL(base)(double x, double _) {
    return atan(pow(x, 3)) / x - x;
}

double CALL(initiate_x)() {
    return -0.5;
}
