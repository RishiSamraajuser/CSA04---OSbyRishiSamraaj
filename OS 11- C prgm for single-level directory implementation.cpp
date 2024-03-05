#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100

// Structure to represent a file
struct File {
    char name[50];
};

// Structure to represent a directory
struct Directory {
    char name[50];
    struct File files[MAX_FILES];
    int fileCount;
};

// Function to display the list of files in a directory
void displayFiles(struct Directory *dir) {
    printf("List of Files in %s:\n", dir->name);
    for (int i = 0; i < dir->fileCount; i++) {
        printf("%s\n", dir->files[i].name);
    }
}

// Function to create a file in a directory
void createFile(struct Directory *dir, char filename[]) {
    if (dir->fileCount < MAX_FILES) {
        strcpy(dir->files[dir->fileCount].name, filename);
        (dir->fileCount)++;
        printf("File created successfully.\n");
    } else {
        printf("Cannot create more files. Limit reached.\n");
    }
}

// Function to delete a file from a directory
void deleteFile(struct Directory *dir, char filename[]) {
    int found = 0;
    for (int i = 0; i < dir->fileCount; i++) {
        if (strcmp(dir->files[i].name, filename) == 0) {
            found = 1;
            for (int j = i; j < dir->fileCount - 1; j++) {
                strcpy(dir->files[j].name, dir->files[j + 1].name);
            }
            (dir->fileCount)--;
            printf("File deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("File not found.\n");
    }
}

int main() {
    struct Directory myDirectory;
    myDirectory.fileCount = 0;

    int choice;
    char filename[50];

    do {
        printf("\nSingle-Level Directory File Operations:\n");
        printf("1. Display Files\n");
        printf("2. Create File\n");
        printf("3. Delete File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFiles(&myDirectory);
                break;
            case 2:
                printf("Enter the name of the file to create: ");
                scanf("%s", filename);
                createFile(&myDirectory, filename);
                break;
            case 3:
                printf("Enter the name of the file to delete: ");
                scanf("%s", filename);
                deleteFile(&myDirectory, filename);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
