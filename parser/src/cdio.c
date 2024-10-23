#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "const.h"
#include "struct.h"

// read string from file
int readString(FILE *f, char *string)
{
    char *ch;

    ch = fgets(string, 100, f);

    if (ch == NULL)
        return EMPTY_STR;

    if (string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';

    if (string[0] == '\0' || string[0] == '\n' || string[0] == '\t')
        return EMPTY_STR;

    return OK;
}

void printErrors(int ch)
{
    if (ch == INCORRECT_ARGS)
        printf("INCORRECT_ARGS\n");

    if (ch == FILE_OPEN_ERR)
        printf("FILE_OPEN_ERR\n");

    if (ch == FILE_CLOSE_ERR)
        printf("FILE_CLOSE_ERR\n");

    if (ch == FILE_ERR)
        printf("FILE_ERR\n");

    if (ch == EMPTY_FILE)
        printf("EMPTY_FILE\n");

    if (ch == INCORRECT_INPUT)
        printf("INCORRECT_INPUT\n");

    if (ch == EMPTY_STR)
        printf("EMPTY_STR\n");
}
