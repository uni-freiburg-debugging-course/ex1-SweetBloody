#include <stdio.h>
#include <string.h>
#include "const.h"
#include "file_process.h"
#include "cdio.h"

int argsCheck(int argc, char **argv)
{
    if (argc != 2)
        return INCORRECT_ARGS;

    // if (strcmp(argv[1], "a") != 0 && strcmp(argv[1], "m") != 0 && strcmp(argv[1], "o") != 0)
    //     return INCORRECT_ARGS;
    //
    // if ((argc == 4 && strcmp(argv[1], "o") != 0) || (argc == 5 && strcmp(argv[1], "o") == 0))
    //     return INCORRECT_ARGS;

    return OK;
}

int fileCheck(char **argv)
{
    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
        return FILE_OPEN_ERR;

    if (ferror(f) != 0)
        return FILE_ERR;

    if (fclose(f) == EOF)
        return FILE_CLOSE_ERR;

    return OK;
}
