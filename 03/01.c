#include "base.h"

/**
 * Написать функцию поиска LastIndexOf() последнего вхождения произвольной подстроки в строке.
 */

static int last_index_of(char *text, char *search)  {
    int ret = -1, i, equals = 0;
    size_t text_len = strlen(text), search_len = strlen(search);

    search_len -= 1;
    for (i = (int)text_len - 1; i >= 0; --i) {
        if (text[i] == search[search_len - equals]) {
            if (search_len == equals) {
                ret = i;
                break;
            }
            ++equals;
        } else {
            equals = 0;
        }
    }
    return ret;
};

char *CALL(task)(struct Argument *args) {
    char buf[20];
    int ret = last_index_of(args->text[0], args->text[1]);

    snprintf(buf, sizeof(buf), "%d", ret);
    return strdup(buf);
}

void CALL(argument_create)(struct Argument *args) {
    args->text_size = 2;
    args->text = (char **)malloc(2 * sizeof(char *));
    args->text[0] = strdup("AAAA0000AAAAAA0000AAAAA0000AAAA");
    args->text[1] = strdup("0000");
    args->result = strdup("23");
}

void CALL(argument_create_argv)(struct Argument *args, int argc, char **argv) {
    args->text = (char **)malloc(2 * sizeof(char *));
    if (argc < 3) {
        fprintf(stdout, "Введите строку поиска : ");
        args->text[0] = read_string();
        fprintf(stdout, "Введите подстроку     : ");
        args->text[1] = read_string();
    } else {
        args->text[0] = strdup(argv[1]);
        args->text[1] = strdup(argv[2]);
    }
    args->text_size = 2;
}