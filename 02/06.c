#include <limits.h>
#include "base.h"

/**
 *
 */
int* CALL(task)(const int *array, size_t size, int *result_size) {
    int *elements = 0, elements_size = 0, n;
    int start = 0, len = 0, max = INT_MIN;

    for (n = 0; n < size; ++n) {
        if (max <= array[n]) {
            ++len;
            max = array[n];
        } else {
            elements = array_add(elements, elements_size++, start);
            elements = array_add(elements, elements_size++, len);
            start = n;
            len = 0;
            max = array[n];
        }
    }

    if (len > 0) {
        elements = array_add(elements, elements_size++, start);
        elements = array_add(elements, elements_size++, len);
    }

    (*result_size) = elements_size;
    return elements;
}

int* CALL(generate_array)(size_t *l_size) {
    return generate_int_array_range(l_size, 0, 10);
}
