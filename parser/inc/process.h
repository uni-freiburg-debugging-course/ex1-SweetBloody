#ifndef PROCESS_H
#define PROCESS_H

#include "const.h"
#include "struct.h"

int evaluateFile(char **argv);

int evaluateExpression(char *expression);

struct TreeNode *getTree(char **expression);

struct TreeNode* parseExpression(char* str);

int evaluateTree(struct TreeNode *node);

#endif // PROCESS_H
