#ifndef CDIO_H
#define CDIO_H

#include <stdio.h>
#include "const.h"

int readString(FILE *f, char *string);

void printErrors(int ch);

#endif // CDIO_H
