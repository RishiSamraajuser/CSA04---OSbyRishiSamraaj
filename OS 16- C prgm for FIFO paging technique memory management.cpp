#include <stdio.h>

#define MAX_FRAMES 3  // Number of frames in memory

void printFrames(int frames[], int n) {
    printf("Frames: ");
    for (int i = 0; i < n; ++i) {
        if (frames[i] == -1) {
            printf(" X ");
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
    return (index + 1) % n;  // Returns the next index for replacement
}

void fifoPageReplacement(int pages[], int n, int frames[], int frameCount) {
    int pageFaults = 0;
    int currentIndex = 0;

    // Initialize frames with -1 (indicating an empty frame)
    for (int i = 0; i < frameCount; ++i) {
        frames[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        printf("Accessing Page(current)-> '%d'\n", pages[i]);
        printFrames(frames, frameCount);

        if (!search(pages[i], frames, frameCount)) {
            // Page Fault: Page not found in frames
            pageFaults++;
            currentIndex = replacePage(frames, frameCount, currentIndex, pages[i]);
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3};
    int n = sizeof(pages) / sizeof(pages[0]);

    int frames[MAX_FRAMES];

    printf("FIFO Page Replacement Simulation\n");
    fifoPageReplacement(pages, n, frames, MAX_FRAMES);

    return 0;
}
