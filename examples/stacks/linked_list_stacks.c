#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// @practice -> linked list implementation of stacks with operations 

typedef struct node {
    struct node *next;
    int value;
} Node; 

bool isEmpty(Node* top) {
    return top == NULL;

}

Node* push(Node* top, int value) {
    Node* node = malloc(sizeof(Node));
    if (!node) return top; // mem alloc fail

    node->value = value; 
    node->next = top;
    top = node;
    printf("pushed %d\n", value);
    return top;
}

Node* pop(Node* top, int *popped) {
    if (isEmpty(top)) return top; // stack underflow

    Node* temp = top; 
    *popped = top->value;
    top = top->next; 
    free(temp);
    printf("popped %d\n", *popped);
    return top;

}

int peek(Node* top) {
    if (isEmpty(top)) {
        return top;
    }

    return top->value;
}

void printStack(Node* top) {
    if (!top) return;

    Node* temp = top;
    while (temp) {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}

int main() {
    Node* top = NULL;
    int poppedVal;

    top = push(top, 30);
    top = push(top, 50);
    top = push(top, 70);

    printStack(top);

    printf("\n----------\n");

    top = pop(top, &poppedVal); 
    printStack(top);

    return 0;
}