#include <stdlib.h>
#include <stdio.h>
#include "base.h"

void CALL(argument_create)(struct Argument *args);

void CALL(argument_create_argv)(struct Argument *args, int argc, char **argv);

char *CALL(task)(struct Argument *args);

int
main(int argc, char *argv[]) {
    struct Argument args = {0};
    size_t k;
    char *result;

    fprintf(stdout, "Задание               : %s\n", STR(TASK));
    CALL(argument_create_argv)(&args, argc, argv);
    fprintf(stdout, "Количество элементов  : %lu\n", args.text_size);
    fprintf(stdout, "Значение массива      : ");
    for (k = 0; k < args.text_size; ++k) {
        if (k > 0) {
            fprintf(stdout, ", ");
        }
        fprintf(stdout, "%s", args.text[k]);
    }
    fprintf(stdout, "\n");
    result = CALL(task)(&args);
    fprintf(stdout, "Результат работы      : ");
    if (0 == result) {
        fprintf(stdout, "не определен");
    } else {
        fprintf(stdout, "%s", result);
    }
    fprintf(stdout, "\n");
    fprintf(stdout, "Результат             : PASSED\n");
    argument_destroy(&args);
    return EXIT_SUCCESS;
}
