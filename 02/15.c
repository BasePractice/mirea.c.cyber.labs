#include <stdio.h>
#include "base.h"

/**
 *
 */
int* CALL(task)(const int *array, size_t size, int *result_size) {
    int *elements = 0, elements_size = 0, n;
    int diff = generate_rand_range(0, 10), sum = 0;

    fprintf(stdout, "Число DIFF            : %d\n", diff);
    for (n = 0; n < size; ++n) {
        sum += array[n];
    }

    sum = sum / size;
    fprintf(stdout, "Среднее арифметическое: %d\n", sum);
    for (n = 0; n < size; ++n) {
        if (array[n] >= sum && array[n] < sum + diff) {
            elements = array_add(elements, elements_size++, array[n]);
        }
    }

    (*result_size) = elements_size;
    return elements;
}

int* CALL(generate_array)(size_t *l_size) {
    return generate_int_array_range(l_size, 0, 10);
}
