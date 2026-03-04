#include <stdio.h>
#include <stdlib.h>
// @practice - linked list insertion deletion 

typedef struct node {
    struct node *next;
    int value;
} node;

node *head = NULL;

void insertAtStart(int val) {
    node* new = malloc(sizeof(node));
    new->value = val;
    new->next = head;
    head = new;
}

void printList(node* head) {
    node *current = head;
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

void deleteNode(int target) {
    if (head == NULL) return; // empty list

    // delete first
    if (head->value == target) {
        node *temp = head; 
        head = head->next;
        free(temp);
    }

    node *prev = head;
    node *current = head->next;

    while (current != NULL) {
        if (current->value == target) {
            prev->next = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    
}

int main() {
    printf("linked list before deletion\n");
    insertAtStart(30); 
    insertAtStart(40);
    insertAtStart(50);
    printList(head);

    printf("\n-----------\n");

    printf("linked list after deletion\n");
    deleteNode(40);
    printList(head);
}