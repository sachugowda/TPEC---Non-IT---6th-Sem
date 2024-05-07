
---

# C Program to Implement Max Heap

This C program demonstrates how to implement a max heap. For a detailed explanation and the complete code, refer to the tutorial on [GeeksforGeeks](https://www.geeksforgeeks.org/c-program-to-implement-max-heap/).

```c
#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the subtree rooted at index i
void maxHeapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

// Function to build a max heap
void buildMaxHeap(int arr[], int n) {
    // Index of the last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal
    // from the last non-leaf node and heapify each node
    for (int i = startIdx; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = { 10, 20, 15, 17, 9, 21 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    // Build max heap
    buildMaxHeap(arr, n);

    printf("Max Heap: \n");
    printArray(arr, n);

    return 0;
}
```

This program demonstrates how to implement a max heap in C. It includes functions to heapify a subtree, build a max heap, and print the array. For a step-by-step explanation, visit [GeeksforGeeks](https://www.geeksforgeeks.org/c-program-to-implement-max-heap/).

--- 
