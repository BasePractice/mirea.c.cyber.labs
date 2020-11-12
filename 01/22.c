#include "base.h"

/**
 * y = ln(x / 2) - x
 * x = 1.8
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_lln(x / 2., eps, divergent) - x;
}

double CALL(base)(double x, double _) {
    return log(x / 2.) - x;
}

double CALL(initiate_x)() {
    return 1.8;
}
