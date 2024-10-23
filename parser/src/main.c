
#include "const.h"
#include "file_process.h"
#include "process.h"
#include "cdio.h"

int main(int argc, char **argv)
{
    int ch = argsCheck(argc, argv);
    if (ch != OK) {
        printErrors(ch);
        return ch;
    }

    ch = fileCheck(argv);
    if (ch != OK) {
        printErrors(ch);
        return ch;
    }

    ch = evaluateFile(argv);
    if (ch != OK) {
        printErrors(ch);
        return ch;
    }

    return OK;
}
