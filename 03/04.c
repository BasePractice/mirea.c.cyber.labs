#include <ctype.h>
#include "base.h"

/*
 * Написать функцию string_to_number(), проверяющую, является ли содержимое строки числом, и возвращающую это число
 * в случае утвердительного ответа.
 */

int to_int(char *text) {
    int result = 0, d = 1;
    int i;
    size_t text_size = strlen(text);

    for (i = text_size - 1; i >= 0; --i) {
        if (!isdigit(text[i]))
            return 0;
        result += d * (text[i] - '0');
        d *= 10;
    }
    return result;
}

char *CALL(task)(struct Argument *args) {
    char buf[20];
    int ret = to_int(args->text[0]);

    snprintf(buf, sizeof(buf), "%d", ret);
    return strdup(buf);
}

void CALL(argument_create)(struct Argument *args) {
    args->text_size = 1;
    args->text = (char **)malloc(1 * sizeof(char *));
    args->text[0] = strdup("36");
    args->result = strdup("36");
}

void CALL(argument_create_argv)(struct Argument *args, int argc, char **argv) {
    args->text = (char **)malloc(1 * sizeof(char *));
    if (argc < 2) {
        fprintf(stdout, "Введите строку        : ");
        args->text[0] = read_string();
    } else {
        args->text[0] = strdup(argv[1]);
    }
    args->text_size = 1;
}
