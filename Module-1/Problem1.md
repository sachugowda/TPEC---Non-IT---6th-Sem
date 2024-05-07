## Problem Statement (Connect `n` ropes with minimal cost)

Link https://www.techiedelight.com/connect-n-ropes-with-minimal-cost/

Given `n` ropes of different lengths, connect them into a single rope with the minimum cost. Assume that the cost to connect two ropes is the same as the sum of their lengths.

For example,

**Input:**  `[5, 4, 2, 8]`  
**Output:** The minimum cost is 36  
Explanation:  
- `[5, 4, 2, 8]` – First, connect ropes of lengths 4 and 2 that will cost 6.
- `[5, 6, 8]` – Next, connect ropes of lengths 5 and 6 that will cost 11.
- `[11, 8]` – Finally, connect the remaining two ropes that will cost 19.  
Therefore, the total cost for connecting all ropes is 6 + 11 + 19 = 36.

## Explanation

The idea is to connect the two lowest-cost ropes first. The resultant rope has a cost equal to the sum of the connected ropes. Repeat the process (with the resultant rope included) until we are left with a single rope.

At each iteration of the loop, we will be left with one less rope, and the optimal cost is added to the total cost. The final cost for connecting `n` ropes will be minimal among all possible combinations. A priority queue implemented using a min-heap is best suited for this problem.

## Solution Explanation

We can solve this problem efficiently using a priority queue (min-heap). The steps are as follows:

1. Push all the ropes into the min-heap.
2. While the heap has more than one element:
   - Pop two smallest ropes from the heap.
   - Connect them and add their sum back to the heap.
3. Finally, the remaining rope in the heap is the single connected rope with the minimum cost.

Let's implement this approach in C:

```c
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers (for min-heap)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function to calculate the minimum cost of connecting ropes
int minCost(int ropes[], int n) {
    // Create a min-heap
    qsort(ropes, n, sizeof(int), compare);

    int totalCost = 0;

    // Iterate until only one rope remains
    while (n > 1) {
        // Extract two smallest ropes from the heap
        int min1 = ropes[0];
        qsort(ropes + 1, n - 1, sizeof(int), compare); // Re-heapify the heap
        int min2 = ropes[1];

        // Connect the two ropes and add their length to total cost
        int sum = min1 + min2;
        totalCost += sum;

        // Remove the two smallest ropes and insert their sum back to the heap
        ropes[0] = sum;
        for (int i = 1; i < n - 1; i++) {
            ropes[i] = ropes[i + 1];
        }
        n--;
    }

    return totalCost;
}

int main() {
    int ropes[] = {5, 4, 2, 8};
    int n = sizeof(ropes) / sizeof(ropes[0]);
    printf("The minimum cost is %d\n", minCost(ropes, n));
    return 0;
}
```

This C program calculates the minimum cost of connecting ropes using a min-heap (priority queue) implemented with the help of the `qsort()` function.
