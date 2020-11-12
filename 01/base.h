#ifndef MIREA_C_CYBER_LABS_BASE_H
#define MIREA_C_CYBER_LABS_BASE_H

#include <stdbool.h>
#include <base_macro.h>
#include <base_math.h>

#if defined(__cplusplus)
#include <cmath>
extern "C" {
#else
#include <math.h>
#endif

#define EPS 0.001

double task(double x, double eps, bool *divergent);
double base(double x, double eps);

double initiate_x();

#if defined(__cplusplus)
}
#endif

#endif //MIREA_C_CYBER_LABS_BASE_H
