#include "base.h"

/**
 * y = (x * 5) / (10 + x^2)
 * x = -1
 */

double CALL(task)(double x, double eps, bool *divergent) {
    /*TODO: Реализовать*/
    return (x * 5)/(10 + pow(x, 2));
}

double CALL(base)(double x, double _) {
    return (x * 5)/(10 + pow(x, 2));
}

double CALL(initiate_x)() {
    return -1;
}
