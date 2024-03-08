#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 1000

void SCAN(int requests[], int n, int start, int direction) {
    int i, j;
    int totalMovement = 0;

    // Sort the requests
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if ((direction == 1 && requests[j] > requests[j + 1]) ||
                (direction == -1 && requests[j] < requests[j + 1])) {
                // Swap
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    int currentIndex = 0;

    // Find the index of the starting request
    while (currentIndex < n && requests[currentIndex] < start) {
        currentIndex++;
    }

    // Move towards the end
    for (i = currentIndex; i < n; i++) {
        printf("Servicing track %d\n", requests[i]);
        totalMovement += abs(requests[i] - start);
        start = requests[i];
    }

    // Move towards the other end
    for (i = currentIndex - 1; i >= 0; i--) {
        printf("Servicing track %d\n", requests[i]);
        totalMovement += abs(requests[i] - start);
        start = requests[i];
    }

    printf("Total head movement: %d\n", totalMovement);
}

int main() {
    int requests[MAX_REQUESTS];
    int n, start, direction;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial position of the disk arm: ");
    scanf("%d", &start);

    printf("Enter the initial direction of the disk arm (1 for right, -1 for left): ");
    scanf("%d", &direction);

    SCAN(requests, n, start, direction);

    return 0;
}
