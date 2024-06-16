# Dynamic Programming

## What is Dynamic Programming?

Dynamic Programming (DP) is a method for solving complex problems by breaking them down into simpler subproblems. It is applicable to problems that exhibit the properties of overlapping subproblems and optimal substructure. DP is often used for optimization problems where the goal is to find the best solution among many possible solutions.

### Key Concepts

1. **Overlapping Subproblems**: This property indicates that the problem can be broken down into smaller subproblems, which are reused several times.
2. **Optimal Substructure**: This property means that the optimal solution to the problem can be constructed from the optimal solutions of its subproblems.
3. **Memoization**: This technique involves storing the results of expensive function calls and reusing them when the same inputs occur again.
4. **Tabulation**: This technique involves building a table in a bottom-up manner to solve the subproblems first and then solve the main problem.

### Example: Fibonacci Sequence

The Fibonacci sequence is a classic example where dynamic programming can be applied. The sequence is defined as:

\[ F(n) = F(n-1) + F(n-2) \]
with base cases:
\[ F(0) = 0 \]
\[ F(1) = 1 \]

We will solve this problem using three different methods: recursion, memoization, and dynamic programming (tabulation).

### 1. Fibonacci using Recursion

Recursion is the simplest way to solve the Fibonacci sequence, but it has a high computational cost due to repeated calculations.

```c
#include <stdio.h>

// Function to calculate Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 1) {
        return n; // Base case: F(0) = 0, F(1) = 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive call
}

int main() {
    int n = 10;
    printf("Fibonacci number at position %d is %d\n", n, fibonacci(n));
    return 0;
}
```

**Explanation**:
- This function calls itself recursively to compute Fibonacci numbers.
- It results in a lot of redundant calculations, making it inefficient for large `n`.

### 2. Fibonacci using Memoization

Memoization is an optimization technique where we store the results of expensive function calls and reuse them when the same inputs occur again.

```c
#include <stdio.h>

#define MAX 1000

// Function to calculate Fibonacci number using memoization
int fibonacci(int n, int memo[]) {
    if (memo[n] != -1) {
        return memo[n]; // Return the stored result if it exists
    }
    if (n <= 1) {
        memo[n] = n; // Base case: F(0) = 0, F(1) = 1
    } else {
        memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo); // Recursive call with memoization
    }
    return memo[n];
}

int main() {
    int n = 10;
    int memo[MAX];
    for (int i = 0; i < MAX; i++) {
        memo[i] = -1; // Initialize memo array with -1
    }
    printf("Fibonacci number at position %d is %d\n", n, fibonacci(n, memo));
    return 0;
}
```

**Explanation**:
- We use an array `memo` to store the results of Fibonacci numbers as we compute them.
- This avoids redundant calculations, making the function much more efficient.

### 3. Fibonacci using Dynamic Programming (Tabulation)

In dynamic programming, we solve the problem in a bottom-up manner, starting from the base cases and building up to the desired solution.

```c
#include <stdio.h>

// Function to calculate Fibonacci number using dynamic programming (tabulation)
int fibonacci(int n) {
    if (n <= 1) {
        return n; // Base case: F(0) = 0, F(1) = 1
    }
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2]; // Fill the dp array from bottom-up
    }
    return dp[n];
}

int main() {
    int n = 10;
    printf("Fibonacci number at position %d is %d\n", n, fibonacci(n));
    return 0;
}
```

**Explanation**:
- We use an array `dp` to store the Fibonacci numbers from `0` to `n`.
- We fill the `dp` array in a bottom-up manner, ensuring that each Fibonacci number is computed only once.

### Comparison

- **Recursion**: Simple but inefficient due to repeated calculations.
- **Memoization**: Optimized recursion by storing intermediate results, avoiding redundant calculations.
- **Dynamic Programming (Tabulation)**: Builds the solution iteratively from the bottom up, avoiding recursion and further reducing overhead.

## Summary

Dynamic programming is a powerful technique for solving problems with overlapping subproblems and optimal substructure. By storing the results of subproblems, we can avoid redundant calculations and achieve significant performance improvements. The Fibonacci sequence example illustrates how dynamic programming can be applied in practice, providing a foundation for tackling more complex problems.

## Related Resources

- [Introduction to Algorithms by Cormen, Leiserson, Rivest, and Stein](https://mitpress.mit.edu/books/introduction-algorithms)
- [GeeksforGeeks - Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming/)
- [HackerRank - Dynamic Programming](https://www.hackerrank.com/domains/tutorials/10-days-of-dp)
- [LeetCode - Dynamic Programming Problems](https://leetcode.com/tag/dynamic-programming/)



---
