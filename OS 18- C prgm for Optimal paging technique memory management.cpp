#include <stdio.h>

// Function to find the index of the page to be replaced
int findOptimal(int pages[], int frames[], int n, int start) {
    int res = -1, farthest = start;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = start; j >= 0; j--) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == -1)
            return i;
    }
    return (res == -1) ? 0 : res;
}

// Function to implement optimal page replacement algorithm
int optimalPageReplacement(int pages[], int n, int capacity) {
    int frames[capacity];
    int pageFaults = 0;

    for (int i = 0; i < capacity; i++)
        frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int flag = 0;

        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            int pos = findOptimal(pages, frames, n, i + 1);
            frames[pos] = pages[i];
            pageFaults++;
        }

        printf("Page %d: ", pages[i]);
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == -1)
                printf("-- ");
            else
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    return pageFaults;
}

int main() {
    int n, capacity;

    // Input number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[n];

    // Input page reference string
    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++) {
        printf("Page %d: ", i + 1);
        scanf("%d", &pages[i]);
    }

    // Input number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &capacity);

    int pageFaults = optimalPageReplacement(pages, n, capacity);

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}
