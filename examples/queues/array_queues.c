#include <stdio.h>
#include <stdbool.h>
// @practice -> array-based implementation of queues with operations

#define MAX_SIZE 10

int q[MAX_SIZE];
int length = 0;
int front = 0;

bool q_empty() {
    return length == 0; 
}

bool q_full() {
    return length == MAX_SIZE;
}

bool enqueue(int n) {
    if (q_full()) return false;

    int end = (front + length) % MAX_SIZE;
    q[end] = n;
    length++;

    return true; 
}

bool dequeue(int *p) {
    if (q_empty()) return false;

    *p = q[front];
    front = (front + 1) % MAX_SIZE;
    length--;

    return true;
}

int peek() {
    if (q_empty()) return -1;
    return q[front];
}

void printQueue() {
    printf("queue:\n");
    for (int i = 0; i < length; i++) {
        int idx = (front + i) % MAX_SIZE; 
        printf("%d\n", q[idx]);
    }
}

int main() {
    int val;

    enqueue(10);
    enqueue(20);
    enqueue(30);

    printQueue();  

    dequeue(&val);
    printf("dequeued: %d\n", val);

    printQueue();  

    enqueue(60);
    printQueue(); 

    printf("front element: %d\n", peek());

    return 0;
}