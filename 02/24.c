#include <stdio.h>
#include "base.h"

/**
 *
 */
int* CALL(task)(const int *array, size_t size, int *result_size) {
    int *elements = 0, elements_size = 0, n;
    int start = -1, end = -1;

    for (n = 0; n < size; ++n) {
        if (0 == array[n] && -1 == start ) {
            start = n;
        }
        if (0 == array[n]) {
            end = n;
        }
    }

    fprintf(stdout, "Начало                : %d\n", start);
    fprintf(stdout, "Окончание             : %d\n", end);

    if (start < end) {
        for (n = start; n <= end && n < size; ++n) {
            elements = array_add(elements, elements_size++, array[n]);
        }
    } else {
        elements = array_add(elements, elements_size++, -1);
    }

    (*result_size) = elements_size;
    return elements;
}

int* CALL(generate_array)(size_t *l_size) {
    return generate_int_array_range(l_size, 0, 10);
}
