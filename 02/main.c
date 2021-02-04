#include <stdlib.h>
#include <stdio.h>
#include "base.h"

int* CALL(generate_array)(size_t *l_size);
int* CALL(task)(const int *array, size_t size, int *result_size);

int
main(int argc, char *argv[]) {
    size_t size;
    size_t k;
    long n;
    int *array, *result, result_size = 0;
    if (argc > 1) {
        n = strtod(argv[1], 0);
    } else {
        n = 10;
    }
    size = n;
    fprintf(stdout, "Задание               : %s\n", STR(TASK));
    array = CALL(generate_array)(&size);
    fprintf(stdout, "Количество элементов  : %llu\n", size);
    fprintf(stdout, "Значение массива      : ");
    for (k = 0; k < size; ++k) {
        if (k > 0) {
            fprintf(stdout, ", ");
        }
        fprintf(stdout, "%d", array[k]);
    }
    fprintf(stdout, "\n");
    result = CALL(task)(array, size, &result_size);
    fprintf(stdout, "Результат работы      : ");
    if (0 == result) {
        fprintf(stdout, "не определен");
    } else {
        for (k = 0; k < result_size; ++k) {
            if (k > 0) {
                fprintf(stdout, ", ");
            }
            fprintf(stdout, "%d", result[k]);
        }
    }
    fprintf(stdout, "\n");
    destroy_array(array);
    destroy_array(result);
    return EXIT_SUCCESS;
}
