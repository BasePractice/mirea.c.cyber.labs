#include <stdio.h>
#include "base.h"

/**
 *
 */
int* CALL(task)(const int *array, size_t size, int *result_size) {
    int *elements = 0, elements_size = 0, n;
    int x = generate_rand_range(0, 5);
    int y = generate_rand_range(0, 5);

    fprintf(stdout, "Элемент X             : %d\n", x);
    fprintf(stdout, "Элемент Y             : %d\n", y);
    for (n = 0; n < size; ++n) {
        if ((array[n] * array[n]) == ((x * x) + (y * y)) && !contains_value(elements, elements_size, array[n])) {
            elements = array_add(elements, elements_size, array[n]);
            ++elements_size;
        }
    }
    (*result_size) = elements_size;
    return elements;
}

int* CALL(generate_array)(size_t *l_size) {
    return generate_int_array_range(l_size, 0, 5);
}
