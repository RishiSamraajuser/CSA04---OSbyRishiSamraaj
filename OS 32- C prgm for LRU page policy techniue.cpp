#include <stdio.h>
#include <stdlib.h>

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

int findLRUIndex(int recent[], int n) {
    int lruIndex = 0;
    for (int i = 1; i < n; i++) {
        if (recent[i] < recent[lruIndex]) {
            lruIndex = i;
        }
    }
    return lruIndex;
}

void lruPageReplacement(int pages[], int n) {
    int frames[MAX_FRAMES];
    int recent[MAX_FRAMES];

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
        recent[i] = 0;
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
                recent[j] = i + 1;
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            int lruIndex = findLRUIndex(recent, MAX_FRAMES);
            frames[lruIndex] = pages[i];
            recent[lruIndex] = i + 1;
            pageFaults++;
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3, 4, 5, 6, 7, 8, 9, 7, 8};
    int n = sizeof(pages) / sizeof(pages[0]);

    lruPageReplacement(pages, n);

    return 0;
}
