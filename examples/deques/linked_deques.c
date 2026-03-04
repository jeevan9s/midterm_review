#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// @practice -> linked deque implementation with operations 

typedef struct node {
    struct node *next;
    struct node *prev;
    int value;
} Node;

typedef struct deque {
    Node *rear;
    Node *front;
} Deque;

bool isEmpty(Deque *d) {
    return d->front == NULL && d->rear == NULL;
}

bool insertFront(Deque *d, int n ) {
    Node *new = malloc(sizeof(Node)); 
    if (!new) return false; // mem alloc error

    new->value = n;
    new->prev = NULL;
    new->next = d->front;

    if (isempty(d)) {
        d->front = d->rear = new; 
    }

    else {
        d->front->next = new;
        d->front = new;
    }

    return true;
}

bool insertRear(Deque* dq, int val) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) return false;

    newNode->value = val;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (isEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        dq->rear->next = newNode;
        dq->rear = newNode;
    }

    return true;
}

bool deleteFront(Deque* dq, int* val) {
    if (isEmpty(dq)) return false;

    Node* temp = dq->front;
    *val = temp->value;

    dq->front = dq->front->next;
    if (dq->front)
        dq->front->prev = NULL;
    else
        dq->rear = NULL; 

    free(temp);
    return true;
}

bool deleteRear(Deque* dq, int* val) {
    if (isEmpty(dq)) return false;

    Node* temp = dq->rear;
    *val = temp->value;

    dq->rear = dq->rear->prev;
    if (dq->rear)
        dq->rear->next = NULL;
    else
        dq->front = NULL; 

    free(temp);
    return true;
}