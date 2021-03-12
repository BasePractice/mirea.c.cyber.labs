#include "base.h"

/**
 * пересекается с третьим заданием и полностью ему соответствует
 */

char * CALL(task)(struct Argument *args) {
    if (0 != args && 0 != args->result) {
        return strdup(args->result);
    }
    return 0;
}

void CALL(argument_create)(struct Argument *args) {

}

void CALL(argument_create_argv)(struct Argument *args, int argc, char **argv) {

}
