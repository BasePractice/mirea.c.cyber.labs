#include "base.h"

/**
 * y = ln(x^2) - x + 1
 * x = 1.5
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_lln(pow(x, 2), eps, divergent) - x + 1;
}

double CALL(base)(double x, double _) {
    return log(pow(x, 2)) - x + 1;
}

double CALL(initiate_x)() {
    return 1.5;
}
