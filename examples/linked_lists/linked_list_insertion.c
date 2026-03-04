#include <stdio.h>;
#include <stdlib.h>
// @practice - linked list insertion operation examples: insert at beginning, middle, end, empty

typedef struct node {
    struct node *next;
    int value;
} node;

node* head = NULL;

void printList(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

void insertAtStart(int val) {
    node* new = malloc(sizeof(node));
    new->value = val;
    new->next = head;
    head = new;
}

void insertAtEnd(int val) {
    node* new = malloc(sizeof(node));
    new->value = val;
    new->next = NULL;

    // list is empty 
    if (head == NULL) {
        head = new; 
        return; 
    }

    // traverse the non empty list
    node *current = head;
    while (current->next != NULL) {
        current = current ->next;
    }

    current->next = new;
}

void insertInBetween(int val, int key) {
    node *new = malloc(sizeof(node));
    new->value = val;
    new->next = NULL;

    node* ptr = head; 
    if (ptr != NULL) {
        while (ptr->value != key && ptr->next != NULL) {
            ptr = ptr->next;
        }
        if (ptr->value == key) {
            new->next = ptr->next;
            ptr->next = new;
        }
    }
}

// bonus
void locateNode(int target) {
    node *ptr = head; 
    while (ptr != NULL) {
        if (ptr->value = target) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

int main() {
    printf("initial list:\n");
    printList(head);

    insertAtStart(10);

    insertAtStart(20);
    insertAtStart(30);
    insertAtEnd(50);
    insertInBetween(25, 30);
    locateNode(10);


    printf("\nlist after insertions\n");
    printList(head);
    return 0;
}