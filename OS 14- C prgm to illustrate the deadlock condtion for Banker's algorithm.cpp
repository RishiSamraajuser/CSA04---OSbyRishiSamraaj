#include <stdio.h>

#define MAX_PROCESSES 8
#define MAX_RESOURCES 5

// Function to check if the system is in a safe state using Banker's algorithm
int isSafe(int available[], int max[][MAX_RESOURCES], int alloc[][MAX_RESOURCES], int need[][MAX_RESOURCES], int processes[]) {
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0}; // Initialize finish array to false

    // Copy available resources to work array
    for (int i = 0; i < MAX_RESOURCES; i++) {
        work[i] = available[i];
    }

    // Check if a process can finish and release its resources
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (finish[i] == 0) {
            int canFinish = 1;
            for (int j = 0; j < MAX_RESOURCES; j++) {
                if (need[i][j] > work[j]) {
                    canFinish = 0;
                    break;
                }
            }

            if (canFinish) {
                // Mark the process as finished and release its resources
                finish[i] = 1;
                for (int j = 0; j < MAX_RESOURCES; j++) {
                    work[j] += alloc[i][j];
                }

                // Add the finished process to the list of safe processes
                printf("P%d ", processes[i]);
            }
        }
    }

    // Check if all processes are in the safe state
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (finish[i] == 0) {
            // Some process is not in the safe state
            return 0;
        }
    }

    // All processes are in the safe state
    return 1;
}

int main() {
    int available[MAX_RESOURCES] = {3, 3, 2};
    int max[MAX_PROCESSES][MAX_RESOURCES] = {
        {7, 5, 3},
        {3, 2, 2},
        {6, 3, 2},
        {2, 2, 2},
        {5, 4, 3},
        {3, 1, 2},
    };
    int alloc[MAX_PROCESSES][MAX_RESOURCES] = {
        {1, 1, 1},
        {2, 1, 0},
        {4, 1, 3},
        {3, 4, 0},
        {2, 1, 0},
        {3, 1, 2},
    };
    int need[MAX_PROCESSES][MAX_RESOURCES];

    // Calculate need matrix
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int processes[MAX_PROCESSES];
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i] = i;
    }

    printf("Safe sequence: ");
    if (isSafe(available, max, alloc, need, processes)) {
        printf("\nThe system is in a safe state.\n");
    } else {
        printf("\nThe system is in a deadlock state.\n");
    }

    return 0;
}
