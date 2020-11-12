#include "base.h"

/**
 * y = 1 / (1 - x)^2
 * x = -0.5
 */

double CALL(task)(double x, double eps, bool *divergent) {
    /*TODO: Реализовать*/
    return 1 / pow(1 - x, 2);
}

double CALL(base)(double x, double _) {
    return 1 / pow(1 - x, 2);
}

double CALL(initiate_x)() {
    return -0.5;
}
