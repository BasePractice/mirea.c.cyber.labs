#include <stdio.h>
#include "base.h"

/**
 *
 */
int* CALL(task)(const int *array, size_t size, int *result_size) {
    int *elements = 0, elements_size = 0, n;
    int *left_side = 0, left_side_size = 0;
    int *right_side = 0, right_side_size = 0;
    int split = generate_rand_range(0, 10);

    fprintf(stdout, "Элемент разделения    : %d\n", split);
    for (n = 0; n < size; ++n) {
        if (array[n] < split) {
            left_side = array_add(left_side, left_side_size++, array[n]);
        } else {
            right_side = array_add(right_side, right_side_size++, array[n]);
        }
    }
    for (n = 0; n < left_side_size; ++n) {
        elements = array_add(elements, elements_size++, left_side[n]);
    }
    for (n = 0; n < right_side_size; ++n) {
        elements = array_add(elements, elements_size++, right_side[n]);
    }
    destroy_array(left_side);
    destroy_array(right_side);
    (*result_size) = elements_size;
    return elements;
}

int* CALL(generate_array)(size_t *l_size) {
    return generate_int_array_range(l_size, 0, 10);
}
