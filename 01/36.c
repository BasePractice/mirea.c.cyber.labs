#include "base.h"

/**
 * y = exp(2 * x^3) - x + 1
 * x = 6 / 7
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_exp(2 * pow(x, 3), eps, divergent) - x + 1;
}

double CALL(base)(double x, double _) {
    return exp(2 * pow(x, 3)) - x + 1;
}

double CALL(initiate_x)() {
    return 6. / 7.;
}
