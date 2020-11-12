#include "base.h"

/**
 * y = ch(x^3)/2 + 5 * x - x^2
 * x = 4/5
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_chn(pow(x, 3), eps, divergent) / 2 + 5 * x - pow(x, 2);
}

double CALL(base)(double x, double _) {
    return cosh(pow(x, 3)) / 2 + 5 * x - pow(x, 2);
}

double CALL(initiate_x)() {
    return 4. / 5.;
}
