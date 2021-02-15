#include "base.h"

/**
 *
 */
int* CALL(task)(const int *array, size_t size, int *result_size) {
    int *elements = 0, elements_size = 0, n;
    int count = 0;

    for (n = 0; n < size; ++n) {
        if (array[n] < 0) {
            ++count;
        }
    }

    for (n = 0; n < count; ++n) {
        elements = array_add(elements, elements_size++, 0);
    }

    for (n = 0; n < size - count; ++n) {
        elements = array_add(elements, elements_size++, array[n]);
    }
    (*result_size) = elements_size;
    return elements;
}

int* CALL(generate_array)(size_t *l_size) {
    return generate_int_array_range(l_size, -5, 5);
}
