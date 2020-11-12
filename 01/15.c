#include "base.h"

/**
 * y = x * ln(x) - 1
 * x = 1.5
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x * x_lln(x, eps, divergent) - 1;
}

double CALL(base)(double x, double _) {
    return x * log(x) - 1;
}

double CALL(initiate_x)() {
    return 1.5;
}
