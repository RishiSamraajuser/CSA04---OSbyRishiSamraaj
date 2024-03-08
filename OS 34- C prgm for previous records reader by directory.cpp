#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100

struct Record {
    char data[100];
};

struct Directory {
    struct Record records[MAX_RECORDS];
    int currentRecord;
};

void initializeDirectory(struct Directory *dir) {
    dir->currentRecord = 0;
}

void addRecord(struct Directory *dir, const char *data) {
    if (dir->currentRecord < MAX_RECORDS) {
        strcpy(dir->records[dir->currentRecord].data, data);
        dir->currentRecord++;
        printf("Record added successfully.\n");
    } else {
        printf("Directory is full. Cannot add more records.\n");
    }
}

void readRecords(struct Directory *dir) {
    if (dir->currentRecord > 0) {
        printf("Reading all previous records:\n");
        for (int i = 0; i < dir->currentRecord; i++) {
            printf("Record %d: %s\n", i + 1, dir->records[i].data);
        }
    } else {
        printf("No records available.\n");
    }
}

int main() {
    struct Directory fileSystem;
    initializeDirectory(&fileSystem);

    addRecord(&fileSystem, "First record");
    addRecord(&fileSystem, "Second record");
    addRecord(&fileSystem, "Third record");

    // Read records before accessing a particular record
    readRecords(&fileSystem);

    // Accessing a specific record
    printf("\nAccessing the current record: %s\n", fileSystem.records[fileSystem.currentRecord - 1].data);

    return 0;
}
