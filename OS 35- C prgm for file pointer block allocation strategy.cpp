#include <stdio.h>

#define MAX_BLOCKS 100

struct File {
    int fileSize;
    int indexBlock[MAX_BLOCKS];
};

void initializeFile(struct File* file, int size) {
    file->fileSize = size;
    for (int i = 0; i < size; i++) {
        file->indexBlock[i] = i; // Pointing each index entry to the corresponding block
    }
}

void printFile(struct File* file) {
    printf("File Size: %d\n", file->fileSize);
    printf("Index Block: ");
    for (int i = 0; i < file->fileSize; i++) {
        printf("%d ", file->indexBlock[i]);
    }
    printf("\n");
}

int main() {
    struct File myFile;
    int fileSize;

    printf("Enter the size of the file: ");
    scanf("%d", &fileSize);

    if (fileSize > MAX_BLOCKS) {
        printf("File size exceeds the maximum limit.\n");
        return 1;
    }

    initializeFile(&myFile, fileSize);
    printFile(&myFile);

    return 0;
}
