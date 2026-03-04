#include <stdio.h>
#include <stdlib.h>
// @practice - integer array insertion operation examples: insert at beginning, middle

void insert_at_beginning(int *arr, int size, int n) {
    int last_idx = size-1;

    for (int i = last_idx; i >= 0; i--) {
        arr[i+1] = arr[i];
    }
    last_idx++;
    arr[0] = n;
}

void insert_in_middle(int *arr, int size, int n, int idx) {
    int last_idx = size-1;

    for (int i = last_idx; i >= idx; i--) {
        arr[i+1] = arr[i];
    }
    last_idx++;
    arr[idx] = n;
}


void print_array(int *arr, int len, char *message) {

    printf("%s\n",message);
    for (int i = 0; i< len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n-------------------\n");
}

int main() {
    int nums[8] = {1, 3, 2, 5, 6};
    int size = sizeof(nums) / sizeof(nums[0]);

    print_array(nums, 5, "nums before insertion"); 

    // insert_at_beginning(nums, size, 1);
    insert_in_middle(nums, 5, 9, 2);
    print_array(nums, 6, "nums after insertion");

}