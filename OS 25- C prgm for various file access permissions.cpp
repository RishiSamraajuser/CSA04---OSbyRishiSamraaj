#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void displayPermissions(mode_t mode) {
    printf("File Permissions: ");

    // Owner permissions
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");

    // Group permissions
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");

    // Others permissions
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");

    printf("\n");
}

void displayUserType(pid_t pid) {
    printf("User Type: ");

    if (pid == 0) {
        printf("Root User (Superuser)\n");
    } else {
        printf("Regular User\n");
    }
}

int main() {
    const char *filename = "example.txt";
    struct stat fileStat;

    // Get file information
    if (stat(filename, &fileStat) == -1) {
        perror("Error getting file information");
        return 1;
    }

    // Display file access permissions
    displayPermissions(fileStat.st_mode);

    // Display user type
    displayUserType(fileStat.st_uid);

    return 0;
}
