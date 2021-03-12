#include "base.h"

/*
 * Написать функцию, вводящую аналог операции “<” для сравнения двух строк (сравнение в алфавитном порядке).
 */

static int compare(char *text1, char *text2)  {
    int it;
    size_t text1_size = strlen(text1), text2_size = strlen(text2);

    for (it = 0; it < text1_size && it < text2_size; ++it) {
        if (text1[it] != text2[it]) {
            if (text1[it] > text2[it]) {
                return 1;
            }
            return -1;
        }
    }

    if (text1_size > text2_size) {
        return -1;
    } else if (text2_size < text1_size) {
        return 1;
    }
    return 0;
};

char * CALL(task)(struct Argument *args) {
    int ret = compare(args->text[0], args->text[1]);

    if (ret > 0) {
        return strdup(">");
    } else if (ret < 0) {
        return strdup("<");
    }
    return strdup("=");
}

void CALL(argument_create)(struct Argument *args) {
    args->text_size = 2;
    args->text = (char **)malloc(2 * sizeof(char *));
    args->text[0] = strdup("000000001");
    args->text[1] = strdup("000000002");
    args->result = strdup("<");
}

void CALL(argument_create_argv)(struct Argument *args, int argc, char **argv) {
    args->text = (char **)malloc(2 * sizeof(char *));
    if (argc < 3) {
        fprintf(stdout, "Введите первую строку : ");
        args->text[0] = read_string();
        fprintf(stdout, "Введите вторую строку : ");
        args->text[1] = read_string();
    } else {
        args->text[0] = strdup(argv[1]);
        args->text[1] = strdup(argv[2]);
    }
    args->text_size = 2;
}