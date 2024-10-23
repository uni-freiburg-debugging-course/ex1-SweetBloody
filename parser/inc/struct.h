#ifndef STRUCT_H
#define STRUCT_H

#include <stdlib.h>


enum Operation {
    NotDefined,
    Add,
    Sub,
    Multi,
    Div
};

enum TokenType {
    Operator,
    Value
};

struct TokenStruct {
    enum TokenType type;
    int *value;
    enum Operation *op;
};

struct TreeNode {
    struct TokenStruct *token;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createOperationNode(const enum Operation op, struct TreeNode* left, struct TreeNode* right);
struct TreeNode* createValueNode(int value);
void freeTree(struct TreeNode *node);

#endif
