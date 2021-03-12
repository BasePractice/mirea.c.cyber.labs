#include <math.h>
#include "base.h"

/*
 * Получить символ, который повторяется наибольшее количества раз. Если таких несколько, то вернуть массив из этих символов
 */

struct Character {
    char ch;
    int count;
};

struct Statistic {
    struct Character *character;
    size_t character_size;
};

static int Character_Compare(const void *d1, const void *d2) {
    if (((struct Character *) d1)->count > ((struct Character *) d2)->count) {
        return -1;
    } else if (((struct Character *) d1)->count > ((struct Character *) d2)->count) {
        return 1;
    }
    return 0;
}

static struct Character *character_add(struct Character *character, size_t character_size, char ch, int count) {
    if (0 == character) {
        character = malloc(sizeof(struct Character));
    } else {
        character = realloc(character, sizeof(struct Character) * (character_size + 1));
    }
    character[character_size].ch = ch;
    character[character_size].count = count;
    return character;
}

static struct Character *character_search(struct Character *character, size_t character_size, char ch) {
    size_t i;

    for (i = 0; i < character_size && 0 != character; ++i) {
        if (character[i].ch == ch)
            return &character[i];
    }
    return 0;
}

static void statistic_add(struct Statistic *statistic, char ch) {
    struct Character *character = character_search(statistic->character, statistic->character_size, ch);
    if (0 != character) {
        character->count++;
    } else {
        statistic->character = character_add(statistic->character, statistic->character_size, ch, 1);
        statistic->character_size++;
    }
}

char *CALL(task)(struct Argument *args) {
    struct Statistic statistic = {0, 0};
    size_t i, text_size = strlen(args->text[0]);
    char buf[20];

    for (i = 0; i < text_size; ++i) {
        statistic_add(&statistic, args->text[0][i]);
    }
    qsort(statistic.character, statistic.character_size, sizeof(struct Character), Character_Compare);
    if (0 == statistic.character) {
        return 0;
    }
    snprintf(buf, sizeof(buf), "%d", statistic.character->count);
    return strdup(buf);
}

void CALL(argument_create)(struct Argument *args) {
    args->text_size = 1;
    args->text = (char **) malloc(1 * sizeof(char *));
    args->text[0] = strdup("000000001");
    args->result = strdup("0");
}

void CALL(argument_create_argv)(struct Argument *args, int argc, char **argv) {
    args->text = (char **) malloc(1 * sizeof(char *));
    if (argc < 3) {
        fprintf(stdout, "Введите строку поиска : ");
        args->text[0] = read_string();
    } else {
        args->text[0] = strdup(argv[1]);
    }
    args->text_size = 1;
}
