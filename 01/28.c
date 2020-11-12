#include "base.h"

/**
 * y = cos(x^5) + 2 * x - 1
 * x = 3/5
 */

double CALL(task)(double x, double eps, bool *divergent) {
    return x_cos(pow(x, 5), eps, divergent) + 2 * x - 1;
}

double CALL(base)(double x, double _) {
    return cos(pow(x, 5)) + 2 * x - 1;
}

double CALL(initiate_x)() {
    return 3. / 5.;
}
