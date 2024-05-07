## Problem Statement (Convert max heap to min heap in linear time)

Link: https://www.techiedelight.com/convert-max-heap-min-heap-linear-time/

Given an array representing a max-heap, in-place convert it into a min-heap in linear time.

## Approach

The idea is simple and efficient, inspired by the Heapsort algorithm. The idea is to build the min-heap in-place using an array representing the max-heap. In other words, this problem is the same as building a min-heap from an unsorted array.

## Solution Explanation

To convert a max-heap to a min-heap, we can simply apply the min-heapify operation to all non-leaf nodes in reverse order. Since leaf nodes are already min-heaps, we start the min-heapify operation from the last non-leaf node and move upwards.

1. Start from the last non-leaf node (`n/2 - 1`) and move towards the root.
2. For each non-leaf node, apply the min-heapify operation.
3. Repeat this process until we reach the root.

Let's implement this approach in C:

```c
#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index i (min-heapify)
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Function to convert a max-heap to a min-heap
void convertMaxHeapToMinHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify each node
    for (int i = (n / 2) - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// Main function
int main() {
    int arr[] = {9, 4, 7, 1, -2, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original max-heap array: ");
    printArray(arr, n);

    convertMaxHeapToMinHeap(arr, n);

    printf("Min-heap array after conversion: ");
    printArray(arr, n);

    return 0;
}
```

This C program converts a max-heap to a min-heap in linear time by applying the min-heapify operation to all non-leaf nodes in reverse order. It then prints the original max-heap array and the min-heap array after conversion.
