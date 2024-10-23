#include "process.h"

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "cdio.h"
#include "struct.h"
#include "const.h"

int evaluateFile(char **argv) {
    FILE *f = fopen(argv[1], "r");
    int ch = OK;
    char expression[MAX_BUF + 1];
    ch = readString(f, expression);
    while (ch == OK) {
        struct TreeNode* root = parseExpression(expression);
        if (root == NULL) {
            return INCORRECT_INPUT;
        }
        printf("%s = ", expression);
        printf("%d\n", evaluateTree(root));
        freeTree(root);
        ch = readString(f, expression);
    }

    if (ch > 0 && ch != EMPTY_STR) {
        fclose(f);
        return INCORRECT_INPUT;
    }

    fclose(f);

    return OK;
}

void skipWhitespace(char** str) {
    while (isspace(**str)) (*str)++;
}

struct TreeNode* parseExpression(char* str) {
    struct TreeNode *root = NULL;

    skipWhitespace(&str);
    if (*str == '(') {
        str++;
    } else {
        return root;
    }

    skipWhitespace(&str);
    if (strncmp(str, "simplify", 8) == 0) {
        str += 8;
    } else {
        return root;
    }

    skipWhitespace(&str);
    str++;
    root = getTree(&str);
    return root;
}

enum Operation parseOperator(char** str) {
    if (strncmp(*str, "+", 1) == 0) {
        (*str)++;
        return Add;
    }
    if (strncmp(*str, "-", 1) == 0) {
        (*str)++;
        return Sub;
    }
    if (strncmp(*str, "*", 1) == 0) {
        (*str)++;
        return Multi;
    }
    if (strncmp(*str, "/", 1) == 0) {
        (*str)++;
        return Div;
    }
    return NotDefined;
}

int parseNumber(char** str) {
    int value = 0;
    int sign = 1;
    if (**str == '-') {
        sign = -1;
        (*str)++;
    }
    while (isdigit(**str)) {
        value = value * 10 + (**str - '0');
        (*str)++;
    }
    return value * sign;
}

struct TreeNode* getTree(char **expression) {
    enum Operation op = parseOperator(expression);
    if (op != NotDefined) {
        (*expression)++;
        skipWhitespace(expression);

        struct TreeNode* left = NULL;
        int number;
        if (**expression == '(') {
            (*expression)++;
            left = getTree(expression);
        } else {
            number = parseNumber(expression);
            left = createValueNode(number);
        }

        skipWhitespace(expression);
        struct TreeNode* right = NULL;
        if (**expression == '(') {
            (*expression)++;
            left = getTree(expression);
        } else {
            number = parseNumber(expression);
            right = createValueNode(number);
        }

        skipWhitespace(expression);
        if (**expression == ')') {
            (*expression)++;
        }
        return createOperationNode(op, left, right);
    }

    return NULL;
}

int evaluateTree(struct TreeNode *node) {
    if (node == NULL) {
        return 0;
    }

    int left = evaluateTree(node->left);
    int right = evaluateTree(node->right);

    switch (node->token->type) {
        case Operator: {
            switch (*node->token->op) {
                case Add: {
                    return left + right;
                }
                case Sub: {
                    return left - right;
                }
                case Multi: {
                    return left * right;
                }
                case Div: {
                    return left / right;
                }
                default: {
                    return 0;
                }
            }
        }
        case Value: {
            return *node->token->value;
        }
    }
    return 0;
}
