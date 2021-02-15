#include <stdio.h>
#include "base.h"

/**
 *
 */
int *CALL(task)(const int *array, size_t size, int *result_size) {
    int *elements = 0, elements_size = 0, n;
    int element = generate_rand_range(0, 10);

    fprintf(stdout, "Число K               : %d\n", element);

    for (n = 0; n < size; ++n) {
        if (array[n] == (3 * element) - 1) {
            if (!contains_value(elements, elements_size, array[n])) {
                elements = array_add(elements, elements_size++, array[n]);
            }
        }
    }
    (*result_size) = elements_size;
    return elements;
}

int *CALL(generate_array)(size_t *l_size) {
    return generate_int_array_range(l_size, 0, 10);
}
