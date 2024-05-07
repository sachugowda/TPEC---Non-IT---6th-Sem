## Problem Statement (Replace each array element by its corresponding rank) https://www.techiedelight.com/replace-each-element-corresponding-rank-array/

Given an array of distinct integers, replace each array element by its corresponding rank in the array.

The minimum array element has the rank 1; the second minimum element has a rank of 2, and so on…

For example,

**Input:**  `{ 10, 8, 15, 12, 6, 20, 1 }`  
**Output:** `{ 4, 3, 6, 5, 2, 7, 1 }`

## Approach

The idea is to store each element’s index in an ordered map (Since the array contains all distinct integers, we can use array elements and their index as key-value pairs in the map). Since elements are stored in sorted order in an ordered map, if we iterate through the map, we get elements in increasing order. Therefore, for each element in increasing order, we start assigning values starting from number 1 to n.

## Solution Explanation

We can solve this problem efficiently using an ordered map (or tree map in C++).

1. Create an ordered map to store each element's index.
2. Iterate through the array and insert each element and its index into the map.
3. Initialize a variable `rank` to 1.
4. Iterate through the ordered map:
   - Assign the current `rank` to the element at the current index.
   - Increment the `rank` by 1.
5. Replace each array element with its corresponding rank.

Let's implement this approach in C:

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to store element-index pairs
typedef struct {
    int element;
    int index;
} Pair;

// Compare function for sorting Pairs by element value
int compare(const void* a, const void* b) {
    return ((Pair*)a)->element - ((Pair*)b)->element;
}

// Function to replace array elements with their ranks
void replaceWithRanks(int arr[], int n) {
    // Create an array of pairs to store element-index pairs
    Pair pairs[n];
    for (int i = 0; i < n; i++) {
        pairs[i].element = arr[i];
        pairs[i].index = i;
    }

    // Sort pairs based on element values
    qsort(pairs, n, sizeof(Pair), compare);

    // Assign ranks to elements
    int rank = 1;
    for (int i = 0; i < n; i++) {
        arr[pairs[i].index] = rank++;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// Main function
int main() {
    int arr[] = {10, 8, 15, 12, 6, 20, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    replaceWithRanks(arr, n);

    printf("Array after replacing with ranks: ");
    printArray(arr, n);

    return 0;
}
```

This C program replaces each array element with its corresponding rank using an ordered map (array of pairs). It then prints the original array and the array after replacing with ranks.
