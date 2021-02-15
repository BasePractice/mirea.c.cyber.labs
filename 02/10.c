#include "base.h"

/**
 *
 */
int* CALL(task)(const int *array, size_t size, int *result_size) {
    int *elements = 0, elements_size = 0, n;

    for (n = 0; n < size; ++n) {
        if (0 == array[n] % 2) {
            elements = array_add(elements, elements_size++, array[n]);
        }
    }
    (*result_size) = elements_size;
    return elements;
}

int* CALL(generate_array)(size_t *l_size) {
    return generate_int_array_range(l_size, 0, 10);
}
