#include <stdio.h>
#include <stdlib.h>
// @practice -> find sum implementation with recursive DFS

typedef struct node {
    int value;
    struct node *left, *right; 
} TreeNode;

int findSum (TreeNode *r) {
    // int sum, leftSum, rightSum; 

    // if (r == NULL) return 0; 

    // leftSum = findSum(r->left);
    // rightSum = findSum(r->right); 

    // sum = r->value + leftSum + rightSum; 

    return (r == NULL ? 0 : r->value + findSum(r->left) + findSum(r->right));
}

TreeNode* createNode(int value) {
    TreeNode *new = malloc(sizeof(TreeNode));
    new->left = NULL;
    new->right = NULL; 
    new->value = value;
    return new;
}

int main() {
    TreeNode *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);

    int total = findSum(root);

    printf("sum: %d\n", total);

    free(root->left);
    free(root->right);
    free(root);

    return 0;
}