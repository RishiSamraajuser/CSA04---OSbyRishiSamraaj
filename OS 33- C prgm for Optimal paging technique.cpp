#include <stdio.h>
#include <limits.h>

#define MAX_FRAMES 3

void displayFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            printf(" |   ");
        } else {
            printf(" | %d ", frames[i]);
        }
    }
    printf("|\n");
}

int findOptimalIndex(int pages[], int frames[], int start, int n) {
    int optimalIndex = -1;
    int farthest = start;

    for (int i = 0; i < MAX_FRAMES; i++) {
        int j;
        for (j = start; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    optimalIndex = i;
                }
                break;
            }
        }

        if (j == n) {
            return i;
        }
    }

    return (optimalIndex == -1) ? 0 : optimalIndex;
}

void optimalPageReplacement(int pages[], int n) {
    int frames[MAX_FRAMES];

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    int pageFaults = 0;

    printf("Page\t  Frames\n");
    printf("----\t  ------\n");

    for (int i = 0; i < n; i++) {
        printf("%2d  |", pages[i]);
        displayFrames(frames, MAX_FRAMES);

        int pageFound = 0;

        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            int index = findOptimalIndex(pages, frames, i + 1, n);
            frames[index] = pages[i];
            pageFaults++;
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3, 4, 5, 6, 7, 8, 9, 7, 8};
    int n = sizeof(pages) / sizeof(pages[0]);

    optimalPageReplacement(pages, n);

    return 0;
}
