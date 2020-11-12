#include "base.h"

/**
 * y = cos(x^2/5) + 2 * x
 * x = 1
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_cos(pow(x, 2) / 5, eps, divergent) + 2 * x;
}

double CALL(base)(double x, double _) {
    return cos(pow(x, 2) / 5) + 2 * x;
}

double CALL(initiate_x)() {
    return 1;
}
