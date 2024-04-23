#include <stdio.h>
#include <string.h>

int main() {
    char data_type[20];
    
    // Prompt the user to enter the data type
    printf("Enter the data type: ");
    scanf("%s", data_type);
    
    // Compare the entered data type and print its size accordingly
    if (strcmp(data_type, "Integer") == 0) {
        printf("Size of %s: 4 bytes\n", data_type);
    } else if (strcmp(data_type, "Long") == 0) {
        printf("Size of %s: 8 bytes\n", data_type);
    } else if (strcmp(data_type, "Float") == 0) {
        printf("Size of %s: 4 bytes\n", data_type);
    } else if (strcmp(data_type, "Double") == 0) {
        printf("Size of %s: 8 bytes\n", data_type);
    } else if (strcmp(data_type, "Character") == 0) {
        printf("Size of %s: 1 byte\n", data_type);
    } else {
        printf("Unknown data type!\n");
    }
    
    return 0;
}
