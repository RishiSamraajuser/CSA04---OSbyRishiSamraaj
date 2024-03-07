#include <stdio.h>
#include <conio.h>
#define MAX_FRAMES 8  // Number of frames in memory

void printFrames(int frames[], int n) {
    printf("Frames: ");
    for (int i = 0; i < n; ++i) {
        if (frames[i] == -1) {
            printf(" - ");
        } else {
            printf(" %d ", frames[i]);
        }
    }
    printf("\n");
}

int search(int key, int frames[], int n) {
    for (int i = 0; i < n; ++i) {
        if (frames[i] == key) {
            return 1;  // Page found in frames
        }
    }
    return 0;  // Page not found in frames
}

int replacePage(int frames[], int n, int index, int key) {
    frames[index] = key;
    return index;
}

void lruPageReplacement(int pages[], int n, int frames[], int frameCount) {
    int pageFaults = 0;
    int recentCounter[MAX_FRAMES] = {0};

    // Initialize frames with -1 (indicating an empty frame)
    for (int i = 0; i < frameCount; ++i) {
        frames[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        printf("Accessing Page-> %d\n", pages[i]);
        printFrames(frames, frameCount);

        int found = search(pages[i], frames, frameCount);

        if (!found) {
            // Page Fault: Page not found in frames
            pageFaults++;

            // Find the least recently used frame
            int minCounterIndex = 0;
            for (int j = 1; j < frameCount; ++j) {
                if (recentCounter[j] < recentCounter[minCounterIndex]) {
                    minCounterIndex = j;
                }
            }

            // Replace the least recently used frame
            replacePage(frames, frameCount, minCounterIndex, pages[i]);
        }

        // Update counters for all frames
        for (int j = 0; j < frameCount; ++j) {
            recentCounter[j]++;
        }

        // Reset counter for the used frame
        if (found) {
            recentCounter[search(pages[i], frames, frameCount) - 1] = 0;
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {2, 3, 1, 5, 4, 6, 5};
    int n = sizeof(pages) / sizeof(pages[0]);

    int frames[MAX_FRAMES];

    printf("LRU Page Replacement Simulation\n");
    lruPageReplacement(pages, n, frames, MAX_FRAMES);

    return 0;
    getch();
}
