#include <stdio.h>
#include <stdlib.h>

// Function to calculate the total head movement
int calculateTotalHeadMovement(int* sequence, int size) {
    int totalHeadMovement = 0;

    for (int i = 1; i < size; ++i) {
        totalHeadMovement += abs(sequence[i] - sequence[i - 1]);
    }

    return totalHeadMovement;
}

int main() {
    int n; // Number of disk requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int* requestSequence = (int*)malloc(n * sizeof(int));
    if (requestSequence == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }

    // Input the disk request sequence
    printf("Enter the disk request sequence:\n");
    for (int i = 0; i < n; ++i) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requestSequence[i]);
    }

    // Calculate total head movement
    int totalHeadMovement = calculateTotalHeadMovement(requestSequence, n);

    // Display the results
    printf("The disk request sequence is: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", requestSequence[i]);
    }
    printf("\n");

    printf("Total head movement: %d\n", totalHeadMovement);

    // Free allocated memory
    free(requestSequence);

    return 0;
}
