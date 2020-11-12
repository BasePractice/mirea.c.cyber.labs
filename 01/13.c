#include "base.h"

/**
 * y = x * sh(x ^ 2)
 * x = 0.5
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x * x_shn(pow(x, 2), eps, divergent);
}

double CALL(base)(double x, double _) {
    return x * sinh(pow(x, 2));
}

double CALL(initiate_x)() {
    return 0.5;
}
