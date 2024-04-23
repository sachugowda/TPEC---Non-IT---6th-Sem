#include <stdio.h>

int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1; // Base case: F(1) = 1 and F(2) = 1
    }

    int a = 1, b = 1, c;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;

    // Prompt the user to enter the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Check if n is within the given constraints
    if (n < 1 || n > 10000) {
        printf("Invalid input. Please enter a value of n between 1 and 10000.\n");
        return 1; // Indicate error
    }

    // Call the fibonacci function to find the n-th Fibonacci number and print it
    printf("The %d-th Fibonacci number is: %d\n", n, fibonacci(n));

    return 0; // Indicate successful termination
}
