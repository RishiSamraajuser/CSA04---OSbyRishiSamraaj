#include <stdio.h>
#include <stdlib.h>

// Function to simulate C-SCAN disk scheduling algorithm
void simulateCSCAN(int requestQueue[], int numRequests, int initialHead) {
    int totalHeadMovement = 0;
    int currentHead = initialHead;
    int visited[numRequests];

    // Initialize visited array
    for (int i = 0; i < numRequests; i++) {
        visited[i] = 0;
    }

    // Sort the request queue in ascending order
    for (int i = 0; i < numRequests - 1; i++) {
        for (int j = 0; j < numRequests - i - 1; j++) {
            if (requestQueue[j] > requestQueue[j + 1]) {
                // Swap requests
                int temp = requestQueue[j];
                requestQueue[j] = requestQueue[j + 1];
                requestQueue[j + 1] = temp;
            }
        }
    }

    // Simulate C-SCAN algorithm
    printf("Sequence of Head Movement:\n");

    // Move the head to the closest end
    printf("Move to the right\n");
    totalHeadMovement += abs(currentHead - requestQueue[0]);
    currentHead = requestQueue[0];

    // Process requests in C-SCAN order
    for (int i = 0; i < numRequests; i++) {
        if (!visited[i]) {
            visited[i] = 1;

            // Calculate head movement for each request
            int headMovement = abs(currentHead - requestQueue[i]);
            totalHeadMovement += headMovement;

            // Move the head to the current request position
            currentHead = requestQueue[i];

            // Print details for each request
            printf("Move to %d (Head Movement: %d)\n", currentHead, headMovement);
        }
    }

    // Move the head to the beginning
    printf("Move to the beginning\n");
    totalHeadMovement += abs(currentHead - 0);
    currentHead = 0;

    // Print the total head movement
    printf("\nTotal Head Movement: %d\n", totalHeadMovement);
}

int main() {
    int numRequests;

    // Input the number of disk requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &numRequests);

    int requestQueue[numRequests];

    // Input the disk request queue
    printf("Enter the disk request queue:\n");
    for (int i = 0; i < numRequests; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requestQueue[i]);
    }

    int initialHead;

    // Input the initial head position
    printf("\nEnter the initial head position: ");
    scanf("%d", &initialHead);

    // Simulate C-SCAN disk scheduling algorithm
    simulateCSCAN(requestQueue, numRequests, initialHead);

    return 0;
}
