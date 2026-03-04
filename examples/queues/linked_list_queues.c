#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// @practice -> linked-list-based implementation of queues with operations

typedef struct node {
    struct node *next; 
    int value;
} Node; 

typedef struct queue {
    Node *rear;
    Node *front;
} Queue;

bool isEmpty(Queue* q) {
    return q->front == NULL && q->rear == NULL;
}

bool enqueue(Queue* q, int n) {
    Node *new = malloc(sizeof(Node));
    if (!new) return false;

    new->value = n; 
    new->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = new; 
    }

    else {
        q->rear->next = new;
        q->rear = new;
    }

    return true;
}

bool dequeue(Queue* q, int *p) {
    if (isEmpty(q)) return false;

    Node *temp = q->front; 
    *p = temp->value;
    q->front = q->front->next;

    if (!q->front) {
        q->rear = NULL;
    }
    free(temp);
    return true; 
}

int peek(Queue* q) {
    if (isEmpty(q)) return -1;
    return q->front->value;

}

void printQueue(Queue* q) {
    Node* temp = q->front;
    printf("queue: ");
    while (temp) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q = {NULL, NULL};
    int val;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printQueue(&q);  

    dequeue(&q, &val);
    printf("Dequeued: %d\n", val);

    printQueue(&q);  

    return 0;
}