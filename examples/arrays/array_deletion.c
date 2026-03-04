#include <stdio.h>
#include <stdlib.h>
// @practice - integer array deletion operation examples: insert at beginning and middle

void delete_from_beginning(int *arr, int size) {
    int last_idx = size-1; 
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i+1];
    }
    last_idx--;
}

void delete_in_middle(int *arr, int size, int idx) {
    int last_idx = size-1;
    for (int i = idx; i < last_idx; i++) {
        arr[i] = arr[i+1];
    }
    idx--;
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

    print_array(nums, 5, "nums before deletion"); 

    // delete_from_beginning(nums, 5);
    delete_in_middle(nums, 5, 1);
    print_array(nums, 4, "nums after deletion");

}