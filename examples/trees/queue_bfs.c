#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Tnode {
    int value;
    struct Tnode *left, *right; 
} TreeNode;

typedef struct node {
    struct node *next; 
    TreeNode *tNode;
} Node; 

typedef struct queue {
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

bool enqueue(Queue* q, TreeNode *t) {
    if (t == NULL) return false;
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) return false;

    newNode->tNode = t; 
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode; 
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    return true;
}

bool dequeue(Queue* q, TreeNode **p) {
    if (isEmpty(q)) return false;

    Node *temp = q->front; 
    *p = temp->tNode;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return true; 
}

void breadth_traverse(TreeNode *root) {
    if (root == NULL) return;

    Queue q; 
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        TreeNode *pNode;
        dequeue(&q, &pNode);

        printf(" %3d", pNode->value); 
        if (pNode->left) enqueue(&q, pNode->left);  
        if (pNode->right) enqueue(&q, pNode->right);
    }
    printf("\n");
}

TreeNode* createTNode(int value) {
    TreeNode* n = malloc(sizeof(TreeNode));
    n->value = value;
    n->left = n->right = NULL;
    return n;
}

int main() {
    TreeNode *root = createTNode(28);
    root->left = createTNode(15);
    root->right = createTNode(37);
    root->left->left = createTNode(4);
    root->left->right = createTNode(25);

    printf("Breadth-First Traversal:");
    breadth_traverse(root);

    return 0;
}