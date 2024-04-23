#include <stdio.h>
#include <math.h> // Include math library for using M_PI constant

// Function to find and print the area based on the choice and input array
void find_area(int ch, float *a) {
    float area;

    // Check the choice and calculate area accordingly
    if (ch == 1) { // If choice is 1 (circle)
        float r = a[0]; // Extract radius from array
        area = M_PI * r * r; // Calculate area of the circle using formula: pi * r^2
        printf("Area of the circle: %f\n", area); // Print the area of the circle
    } else if (ch == 2) { // If choice is 2 (rectangle)
        float l = a[0]; // Extract length from array
        float b = a[1]; // Extract breadth from array
        area = l * b; // Calculate area of the rectangle using formula: length * breadth
        printf("Area of the rectangle: %f\n", area); // Print the area of the rectangle
    } else { // If choice is neither 1 nor 2
        printf("Invalid choice\n"); // Print message indicating invalid choice
    }
}

int main() {
    int ch; // Variable to store choice
    float a[2]; // Array to store input values (radius or length and breadth)

    // Prompt the user to enter the choice (1 for circle, 2 for rectangle)
    printf("Enter the choice (1 for circle, 2 for rectangle): ");
    scanf("%d", &ch); // Read the choice entered by the user

    // Check the choice and proceed accordingly
    if (ch == 1) { // If choice is 1 (circle)
        printf("Enter the radius of the circle: ");
        scanf("%f", &a[0]); // Read the radius entered by the user
        find_area(ch, a); // Call the function to find and print the area of the circle
    } else if (ch == 2) { // If choice is 2 (rectangle)
        printf("Enter the length and breadth of the rectangle: ");
        scanf("%f %f", &a[0], &a[1]); // Read the length and breadth entered by the user
        find_area(ch, a); // Call the function to find and print the area of the rectangle
    } else { // If choice is neither 1 nor 2
        printf("Invalid choice\n"); // Print message indicating invalid choice
    }

    return 0; // Indicate successful termination of program
}
