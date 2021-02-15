#include <stdio.h>
#include <limits.h>
#include "base.h"

/**
 *
 */
int* CALL(task)(const int *array, size_t size, int *result_size) {
    int *elements = 0, elements_size = 0, n;
    int max = array[0], min = array[0], start = -1, end = -1;

    for (n = 0; n < size; ++n) {
        if (max < array[n]) {
            max = array[n];
        }
        if (min > array[n]) {
            min = array[n];
        }
    }

    fprintf(stdout, "Максимум              : %d\n", max);
    fprintf(stdout, "Минимум               : %d\n", min);

    for (n = 0; n < size; ++n) {
        if (-1 == start && max == array[n]) {
            start = n;
        }
        if (min == array[n]) {
            end = n;
        }
    }

    if (start < end && start != -1 && end != -1) {
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
