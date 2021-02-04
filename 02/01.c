#include <limits.h>
#include "base.h"

static int* search_index(const int *array, size_t array_size, int search_value, int *index_size) {
    size_t n;
    int *result = 0;
    size_t result_size = 0;

    for (n = 0; n < array_size; ++n) {
        if (array[n] == search_value) {
            result = array_add(result, result_size, n);
            ++result_size;
        }
    }
    (*index_size) = result_size;
    return result;
}

int* CALL(task)(const int *array, size_t size, int *result_size) {
    int max = INT_MIN;
    size_t k;

    for (k = 0; k < size; ++k) {
        if (array[k] > max) {
            max = array[k];
        }
    }
    return search_index(array, size, max, result_size);
}

int* CALL(generate_array)(size_t *l_size) {
    return generate_int_array_range(l_size, 0, 10);
}