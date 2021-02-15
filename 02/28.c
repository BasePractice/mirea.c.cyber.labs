#include "base.h"

/**
 *
 */
int* CALL(task)(const int *array, size_t size, int *result_size) {
    int *elements = 0, elements_size = 0, n;

    elements = array_add(elements, elements_size++, array[0]);
    for (n = 1; n < size - 1; ++n) {
        int sum = (array[n - 1] + array[n] + array[n + 1]) / 3;
        elements = array_add(elements, elements_size++, sum);
    }
    elements = array_add(elements, elements_size++, array[size - 1]);
    (*result_size) = elements_size;
    return elements;
}

int* CALL(generate_array)(size_t *l_size) {
    return generate_int_array_range(l_size, 0, 10);
}
