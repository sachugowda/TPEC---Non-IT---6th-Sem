//Problem statement
//Write a program that takes a character as input and prints 1, 0, or -1 according to the following rules.

// 1, if the character is an uppercase alphabet (A - Z).
// 0, if the character is a lowercase alphabet (a - z).
-// 1, if the character is not an alphabet.

// Example:
Input: The character is 'a'.

// Output: 0

// Explanation: The input character is lowercase, so our answer is 0.




#include <stdio.h>

// Function to check the type of character
int check_char(char character) {
    // Check if the character is an uppercase alphabet
    if (character >= 'A' && character <= 'Z') {
        return 1; // Return 1 if uppercase
    }
    // Check if the character is a lowercase alphabet
    else if (character >= 'a' && character <= 'z') {
        return 0; // Return 0 if lowercase
    }
    else {
        return -1; // Return -1 if not an alphabet
    }
}

// Main function
int main() {
    char character; // Variable to store the input character
    
    // Prompt the user to enter a character
    printf("Enter a character: ");
    // Read the character input from the user
    scanf("%c", &character);
    
    // Call the check_char function with the input character
    int result = check_char(character);
    
    // Print the result based on the returned value
    printf("Output: %d\n", result);
    
    return 0; // Indicate successful program execution
}

