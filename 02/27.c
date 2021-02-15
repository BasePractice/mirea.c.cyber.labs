#include <stdio.h>
#include "base.h"

/**
 *
 */
int* CALL(task)(const int *array, size_t size, int *result_size) {
    int *elements = 0, elements_size = 0, n;
    int *contains = 0, contains_size = 0, sum = 0;
    int *temporary = 0, temporary_size = 0;

    for (n = 0; n < size; ++n) {
        sum += array[n];

        if (!contains_value(temporary, temporary_size, array[n])) {
            temporary = array_add(temporary, temporary_size++, array[n]);
        } else if (!contains_value(contains, contains_size, array[n])) {
            contains = array_add(contains, contains_size++, array[n]);
        }
    }

    sum = sum / size;
    fprintf(stdout, "Среднее арифметическое: %d\n", sum);

    for (n = 0; n < size; ++n) {
        if (contains_value(contains, contains_size, array[n])) {
            elements = array_add(elements, elements_size++, sum);
        } else {
            elements = array_add(elements, elements_size++, array[n]);
        }
    }

    destroy_array(contains);
    destroy_array(temporary);
    (*result_size) = elements_size;
    return elements;
}

int* CALL(generate_array)(size_t *l_size) {
    return generate_int_array_range(l_size, 0, 10);
}
