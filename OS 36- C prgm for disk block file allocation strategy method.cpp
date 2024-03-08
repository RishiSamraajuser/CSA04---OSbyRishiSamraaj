#include <stdio.h>
#include <stdlib.h>

struct Block {
    int data;
    struct Block* next;
};

struct File {
    struct Block* firstBlock;
    struct Block* lastBlock;
};

void initializeFile(struct File* file) {
    file->firstBlock = NULL;
    file->lastBlock = NULL;
}

void addBlock(struct File* file, int data) {
    struct Block* newBlock = (struct Block*)malloc(sizeof(struct Block));
    if (newBlock == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    newBlock->data = data;
    newBlock->next = NULL;

    if (file->firstBlock == NULL) {
        // If it's the first block
        file->firstBlock = newBlock;
        file->lastBlock = newBlock;
    } else {
        // If it's not the first block, link it to the last block
        file->lastBlock->next = newBlock;
        file->lastBlock = newBlock;
    }
}

void printFile(struct File* file) {
    struct Block* currentBlock = file->firstBlock;

    while (currentBlock != NULL) {
        printf("%d -> ", currentBlock->data);
        currentBlock = currentBlock->next;
    }

    printf("NULL\n");
}

void freeBlocks(struct File* file) {
    struct Block* currentBlock = file->firstBlock;
    struct Block* nextBlock;

    while (currentBlock != NULL) {
        nextBlock = currentBlock->next;
        free(currentBlock);
        currentBlock = nextBlock;
    }

    file->firstBlock = NULL;
    file->lastBlock = NULL;
}

int main() {
    struct File myFile;
    
    initializeFile(&myFile);

    addBlock(&myFile, 10);
    addBlock(&myFile, 20);
    addBlock(&myFile, 30);

    printf("File Contents: ");
    printFile(&myFile);

    // Clean up allocated memory
    freeBlocks(&myFile);

    return 0;
}
