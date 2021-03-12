#ifndef MIREA_C_CYBER_LABS_BASE_H
#define MIREA_C_CYBER_LABS_BASE_H

#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <base_macro.h>
#include <base_math.h>

#if defined(__cplusplus)
#include <cmath>
extern "C" {
#else
#include <math.h>
#endif

struct Argument {
    char  *result;
    char **text;
    size_t text_size;
};

char *read_string();

void argument_create_argv(struct Argument *args, int argc, char **argv);
void argument_destroy(struct Argument *args);

char *task(struct Argument *args);

#if defined(__cplusplus)
}
#endif

#endif //MIREA_C_CYBER_LABS_BASE_H
