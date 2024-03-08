#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;  // Declare a pointer to int

    // Get the size of the array from the user
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array
    array = (int *)malloc(size * sizeof(int));

    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;  // Exit the program with an error code
    }

    // Input values into the array
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Display the elements of the array
    printf("Array elements are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    // Free the dynamically allocated memory
    free(array);

    return 0;
}
