#ifndef STRUCT_H
#define STRUCT_H

#include <stdlib.h>


// const char* KeyWordSimplify = "simplify";
// const char LBracketValue = '(';
// const char RBracketValue = ')';

enum Operation {
    NotDefined,
    Add,
    Sub,
    Multi,
    Div
};

enum TokenType {
    // KeyWord,
    // LBracket,
    // RBracket,
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
