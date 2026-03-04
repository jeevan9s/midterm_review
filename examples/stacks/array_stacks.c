#include <stdio.h>
#include <stdbool.h>
// @practice - sequential implementation of stack and operations

#define MAX 100

typedef enum {FAIL, OK} rslt; 

typedef struct {
    int arr[MAX]; 
    int top; 
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isFull(Stack *stack) {
    return stack->top == MAX-1;
}

int tos(Stack *stack) {
    return stack->top;
}

int push(Stack *stack, int n) {
    if (isFull(stack)) return FAIL; // stack overflow
    stack->arr[++stack->top] = n; 
    printf("pushed %d\n", n);
}

int pop(Stack *stack) {
    if (isEmpty(stack)) return FAIL; // stack underflow
    
    int popped = stack->arr[stack->top]; 
    stack->top--;
    printf("popped %d\n", popped); 
    return popped;
}

int peek(Stack *stack) {
    if (isEmpty(stack)) return FAIL;
    return stack->arr[stack->top];
}

void printStack(Stack *stack) {
    if (isEmpty(stack)) return FAIL; 

    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->arr[i]);
    }
}



int main() {
    Stack stack;
    initStack(&stack); 

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    printf("\n----------------\n"); 
    printStack(&stack);

    pop(&stack);
    printStack(&stack);
}