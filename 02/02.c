#include <stdbool.h>
#include "base.h"

/**
 *
 */

inline bool is_prime(int numb) {
    int i;

    for (i = 2; i < numb; ++i) {
        if (0 == numb % i) {
            return false;
        }
    }
    return true;
}

int* CALL(task)(const int *array, size_t size, int *result_size) {
    size_t n;
    int *prime = 0, prime_size = 0;

    for (n = 0; n < size; ++n) {
        if (is_prime(array[n]) && !contains_value(prime, prime_size, array[n])) {
            prime = array_add(prime, prime_size, array[n]);
            ++prime_size;
        }
    }
    (*result_size) = prime_size;
    return prime;
}

int* CALL(generate_array)(size_t *l_size) {
    return generate_int_array_range(l_size, 0, 10);
}
