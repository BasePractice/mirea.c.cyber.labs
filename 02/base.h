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

int generate_rand_range(int begin, int end);
int* generate_int_array(size_t *l_size);
int* generate_int_array_range(size_t *l_size, int begin, int end);
void destroy_array(void *);
void extract(int numb, int *ext, size_t size);
bool contains_value(const int *array, int array_size, int value);
int *array_add(int *array, size_t array_size, int value);


#if defined(__cplusplus)
}
#endif

#endif //MIREA_C_CYBER_LABS_BASE_H
