#include "base.h"

/**
 * y = x * argctg(x ^ 2) - 1
 * x = -1
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x * x_atg(pow(x, 2), eps, divergent) - 1;
}

double CALL(base)(double x, double _) {
    return x * atan(pow(x, 2)) - 1;
}

double CALL(initiate_x)() {
    return -1;
}
