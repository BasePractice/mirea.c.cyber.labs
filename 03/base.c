#include <time.h>
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include "base.h"

char *read_string() {
    char *text = 0;
    int symbol, c = 0;
    size_t text_allocated = 0;

    while ((symbol = fgetc(stdin)) != '\n') {
        if (0 == text) {
            text_allocated = 256;
            text = calloc(text_allocated, 1);
        } else if (text_allocated <= c) {
            text_allocated += 256;
            text = realloc(text, text_allocated);
        }
        text[c++] = (char) symbol;
    }
    if (0 != text)
        text[c] = 0;
    return text;
}

void argument_destroy(struct Argument *args) {
    if (0 != args && 0 != args->text) {
        size_t i;

        for (i = 0; i < args->text_size; ++i) {
            if (0 != args->text[i])
                free(args->text[i]);
        }
        free(args->text);
        args->text = 0;
        args->text_size = 0;
    }

    if (0 != args && 0 != args->result) {
        free(args->result);
        args->result = 0;
    }
}
