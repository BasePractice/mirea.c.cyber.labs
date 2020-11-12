#include "base.h"

/**
 * y = exp(-x^3) - x - 1
 * x = 3/4
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_exp(pow(-x, 3), eps, divergent) - x - 1;
}

double CALL(base)(double x, double _) {
    return exp(pow(-x, 3)) - x - 1;
}

double CALL(initiate_x)() {
    return 3. / 4.;
}
