#include "base.h"

/**
 * y = sh(2 * x^2)/x - 1 - x^2
 * x = 3/4
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_shn(2 * pow(x, 2), eps, divergent) / x - 1 - pow(x, 2);
}

double CALL(base)(double x, double _) {
    return sinh(2 * pow(x, 2)) / x - 1 - pow(x, 2);
}

double CALL(initiate_x)() {
    return 3. / 4.;
}
