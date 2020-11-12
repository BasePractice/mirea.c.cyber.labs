#include "base.h"

/**
 * y = x * sin(2 * x^4) - 3 * x^3
 * x = -3/7
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x * x_sin(2 * pow(x, 4), eps, divergent) - 3 * pow(x, 3);
}

double CALL(base)(double x, double _) {
    return x * sin(2 * pow(x, 4)) - 3 * pow(x, 3);
}

double CALL(initiate_x)() {
    return -3. / 7.;
}
