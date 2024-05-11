# Heap Sort Algorithm

Heap sort is a comparison-based sorting algorithm that uses a binary heap data structure to sort elements. It is a popular sorting algorithm due to its efficiency and simplicity.

## How Heap Sort Works

1. **Build Heap**: First, the input array is transformed into a max-heap. This is achieved by starting from the last non-leaf node and heapifying each subtree in a bottom-up manner.
2. **Heapify**: Heapify ensures that the heap property is maintained. In max heap, it compares the parent node with its children and swaps if necessary to maintain the heap property.
3. **Extract Max and Heapify**: Once the heap is built, the maximum element (root of the heap) is extracted and placed at the end of the array. The heap is then reconstructed by heapifying the remaining elements.
4. **Repeat**: Steps 3 is repeated for the remaining elements until the entire array is sorted.


```markdown


## Implementation of Heap Sort in C


#include <stdio.h>

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to perform heap sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
```

This C program demonstrates the heap sort algorithm on an array of integers.

## Time Complexity

Heap sort has a time complexity of O(n log n) for all cases, where n is the number of elements in the input array. This makes it an efficient sorting algorithm for large datasets.

Heap sort is an in-place algorithm, meaning it doesn't require additional storage proportional to the input size, making it memory efficient as well.

To learn more about heap sort and its implementation, visit [GeeksforGeeks - Heap Sort](https://www.geeksforgeeks.org/heap-sort/).
```
