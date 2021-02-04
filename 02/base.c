#include <time.h>
#include <memory.h>
#include <stdlib.h>
#include "base.h"

int generate_rand_range(int begin, int end) {
    return rand() % (end - begin + 1) + begin;
}

int* generate_int_array(size_t *l_size) {
    return generate_int_array_range(l_size, 0, 100);
}

int* generate_int_array_range(size_t *l_size, int begin, int end) {
    size_t n;
    int *array;
    if (0 == l_size)
        return 0;
    srand(time(0));
    if (*l_size <= 0) {
        (*l_size) = generate_rand_range(1, 100);
    }
    array = calloc((*l_size), sizeof(int));
    for (n = 0; n < (*l_size); ++n) {
        array[n] = generate_rand_range(begin, end);
    }
    return array;
}

void destroy_array(void *mem) {
    if (0 != mem) {
        free(mem);
    }
}

void extract(int numb, int *ext, size_t size) {
    size_t n;

    memset(ext, 0, size * sizeof(int));
    for (n = size - 1; n >= 0 && numb > 0; --n) {
        ext[n] = numb % 10;
        numb = numb / 10;
    }
}

int *array_add(int *array, size_t array_size, int value) {
    if (0 == array) {
        array_size = 0;
        array = calloc(1, sizeof(int));
    } else {
        array = realloc(array, (array_size + 1) * sizeof(int));
    }
    array[array_size] = value;
    return array;
}

bool contains_value(const int *array, int array_size, int value) {
    int i;

    for (i = 0; 0 != array && i < array_size; ++i) {
        if (array[i] == value) {
            return true;
        }
    }
    return false;
}

