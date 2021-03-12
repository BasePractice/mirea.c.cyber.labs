#include <ctype.h>
#include "base.h"

/*
 * Написать функции, реализующие код Цезаря (и кодирование, декодирование): буква заменяется на следующую за ней в
 * алфавите (“test”->”uftu”)
 */

static void crypt(char *text) {
    int it = 0;

    while (0 != text[it]) {
        if (isalpha(text[it])) {
            text[it]++;
        }
        ++it;
    }
}

static void decrypt(char *text) {
    int it = 0;

    while (0 != text[it]) {
        if (isalpha(text[it])) {
            text[it]--;
        }
        ++it;
    }
}

char * CALL(task)(struct Argument *args) {
    char *text = strdup(args->text[0]);

    crypt(text);
    decrypt(text);
    return text;
}

void CALL(argument_create)(struct Argument *args) {
    args->text_size = 1;
    args->text = (char **) malloc(1 * sizeof(char *));
    args->text[0] = strdup("abcdefg");
    args->result = strdup("abcdefg");
}

void CALL(argument_create_argv)(struct Argument *args, int argc, char **argv) {
    args->text = (char **) malloc(1 * sizeof(char *));
    if (argc < 2) {
        fprintf(stdout, "Введите строку шифра  : ");
        args->text[0] = read_string();
    } else {
        args->text[0] = strdup(argv[1]);
    }
    args->text_size = 1;
}
