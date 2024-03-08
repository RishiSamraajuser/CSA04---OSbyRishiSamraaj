#include <stdio.h>
#include <stdbool.h>

#define NUM_FRAMES 3

// Function to check if a page is present in frames
bool isPagePresent(int page, int frames[], int numFrames) {
    for (int i = 0; i < numFrames; ++i) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

// Function to perform FIFO page replacement
void fifoPageReplacement(int pages[], int numPages) {
    int frames[NUM_FRAMES];  // Array to represent page frames
    int frameIndex = 0;      // Index to track the next frame to replace

    // Initialize frames to -1 (indicating empty)
    for (int i = 0; i < NUM_FRAMES; ++i) {
        frames[i] = -1;
    }

    printf("Page Reference Sequence: ");
    for (int i = 0; i < numPages; ++i) {
        int currentPage = pages[i];

        printf("%d ", currentPage);

        if (!isPagePresent(currentPage, frames, NUM_FRAMES)) {
            // Page fault: replace the oldest page using FIFO
            frames[frameIndex] = currentPage;
            frameIndex = (frameIndex + 1) % NUM_FRAMES;

            // Print the current state of frames after a page fault
            printf("\tFrames: ");
            for (int j = 0; j < NUM_FRAMES; ++j) {
                printf("%d ", frames[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    // Example page reference sequence
    int pageReferences[] = {0, 1, 2, 0, 3, 4, 2, 3, 0, 3, 1, 2, 4, 1, 4, 2, 5, 3, 5};

    int numPages = sizeof(pageReferences) / sizeof(pageReferences[0]);

    printf("FIFO Page Replacement Simulation:\n");
    fifoPageReplacement(pageReferences, numPages);

    return 0;
}
