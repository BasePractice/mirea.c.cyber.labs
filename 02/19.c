#include "base.h"

/**
 *
 */
int* CALL(task)(const int *array, size_t size, int *result_size) {
    int *elements = 0, elements_size = 0, n;
    int export[5];

    for (n = 0; n < size; ++n) {
        extract(array[n], export, 5);
        if ( (export[0] * export[1]) == (export[2] * export[3]) && (export[2] * export[3]) == export[4]) {
            elements = array_add(elements, elements_size, array[n]);
            ++elements_size;
        }
    }
    (*result_size) = elements_size;
    return elements;
}

int* CALL(generate_array)(size_t *l_size) {
    return generate_int_array_range(l_size, 10000, 99999);
}
