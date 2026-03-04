#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// @practice -> iterative depth-first traversal

typedef struct node {
    struct Tnode *tNode; 
    struct node *next;
} Node; 

typedef struct stack {
    Node *top; 
} Stack;

typedef struct Tnode {
    int value;
    struct Tnode *left, *right; 
} TreeNode;

bool isEmpty(Node* top) {
    return top == NULL;
}

TreeNode* createTNode(int value) {
    TreeNode* n = malloc(sizeof(TreeNode));
    n->value = value;
    n->left = n->right = NULL;
    return n;
}

Node* push(Node* top, TreeNode* t) {
    if (t == NULL) return top;
    Node* node = malloc(sizeof(Node));
    node->tNode = t; 
    node->next = top;
    return node;
}

Node* pop(Node* top, TreeNode **popped) {
    if (isEmpty(top)) return top;
    Node* temp = top; 
    *popped = top->tNode;
    top = top->next; 
    free(temp);
    return top;
}

void iterative_dfs(TreeNode *r) {
    if (r == NULL) return;
    Node *stackTop = NULL;
    stackTop = push(stackTop, r); 

    while (!isEmpty(stackTop)) {
        TreeNode *current;
        stackTop = pop(stackTop, &current);
        printf("%d ", current->value);
        
        if (current->right) stackTop = push(stackTop, current->right);
        if (current->left) stackTop = push(stackTop, current->left);
    }
    printf("\n");
}

int main() {
    TreeNode *root = createTNode(28);
    root->left = createTNode(15);
    root->right = createTNode(37);
    root->left->left = createTNode(4);
    root->left->right = createTNode(25);

    iterative_dfs(root);

    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}