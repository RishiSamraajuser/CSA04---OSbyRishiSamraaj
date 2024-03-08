#include <stdio.h>
#include <stdlib.h>

void displayFileContents(FILE *file) {
    char ch;
    printf("File Contents:\n");

    // Read and display each character in the file
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    printf("\n");
}

void editFile(FILE *file) {
    // Move the file pointer to the beginning of the file
    fseek(file, 0, SEEK_SET);

    printf("Enter new content (Ctrl+D to save and exit):\n");

    // Read user input and write it to the file
    char ch;
    while ((ch = getchar()) != EOF) {
        fputc(ch, file);
    }
}

int main() {
    const char *filename = "example.txt";
    FILE *file;

    // Open the file in read mode
    file = fopen(filename, "r");

    // Check if the file exists
    if (file == NULL) {
        printf("File does not exist. Creating a new file.\n");

        // Create a new file in write mode
        file = fopen(filename, "w");

        if (file == NULL) {
            perror("Error creating the file");
            return 1;
        }

        // Close the file after creation
        fclose(file);

        // Reopen the file in read/write mode
        file = fopen(filename, "r+");
    }

    // Display current file contents
    displayFileContents(file);

    // Allow the user to edit the file
    editFile(file);

    // Display updated file contents
    displayFileContents(file);

    // Close the file
    fclose(file);

    return 0;
}
