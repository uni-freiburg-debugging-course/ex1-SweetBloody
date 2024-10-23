#include "struct.h"

struct TokenStruct* createTokenValue(int value) {
    struct TokenStruct* token = malloc(sizeof(struct TokenStruct));
    if (token == NULL) {
        return NULL;
    }

    token->type = Value;
    token->value = malloc(sizeof(int));
    *token->value = value;
    token->op = NULL;

    return token;
}

struct TokenStruct* createTokenOperation(enum Operation op) {
    struct TokenStruct* token = (struct TokenStruct*)malloc(sizeof(struct TokenStruct));
    if (token == NULL) {
        return NULL;
    }

    token->type = Operator;
    token->value = NULL;
    token->op = malloc(sizeof(enum Operation));
    *token->op = op;

    return token;
}

struct TreeNode* createOperationNode(const enum Operation op, struct TreeNode* left, struct TreeNode* right) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->left = left;
    node->right = right;
    node->token = createTokenOperation(op);
    return node;
}

struct TreeNode* createValueNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->left = NULL;
    node->right = NULL;
    node->token = createTokenValue(value);
    return node;
}


void freeTokenStruct(struct TokenStruct *token) {
    if (token != NULL) {
        if (token->value != NULL) {
            free(token->value);
        }

        free(token);
    }
}

void freeTree(struct TreeNode *node) {
    if (node == NULL) {
        return;
    }

    freeTree(node->left);
    freeTree(node->right);
    freeTokenStruct(node->token);
    free(node);
}
