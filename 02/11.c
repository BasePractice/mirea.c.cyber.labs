#include "base.h"

/**
 *
 */
int* CALL(task)(const int *array, size_t size, int *result_size) {
    return 0;
}

int* CALL(generate_array)(size_t *l_size) {
    return generate_int_array_range(l_size, 0, 10);
}
