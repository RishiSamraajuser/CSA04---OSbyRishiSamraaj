#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    // Open the current directory
    DIR *dir = opendir(".");

    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    // Read directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Ignore entries for current directory (.) and parent directory (..)
        if (entry->d_name[0] != '.') {
            printf("%s\n", entry->d_name);
        }
    }

    // Close the directory
    closedir(dir);

    return 0;
}
