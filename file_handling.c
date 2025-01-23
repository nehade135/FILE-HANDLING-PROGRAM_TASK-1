#include <stdio.h>
#include <stdlib.h>
void createFile() {
    FILE *file = fopen("example1.txt", "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        return;
    }
    printf("File created successfully!\n");
    fclose(file);
}

void writeFile() {
    FILE *file = fopen("example1.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "Hello, this is a sample text.\n");
    printf("Data written to file successfully!\n");
    fclose(file);
}

void readFile() {
    char buffer[255];
    FILE *file = fopen("example1.txt", "r");
    if (file == NULL) {
        printf("Error reading file!\n");
        return;
    }
    printf("File contents:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

void appendFile() {
    FILE *file = fopen("example1.txt", "a");
    if (file == NULL) {
        printf("Error opening file for appending!\n");
        return;
    }
    fprintf(file, "This is appended text.\n");
    printf("Data appended to file successfully!\n");
    fclose(file);
}

int main() {
    int choice;

    do {
        printf("\nFile Operations Menu:\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Read from File\n");
        printf("4. Append to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createFile(); break;
            case 2: writeFile(); break;
            case 3: readFile(); break;
            case 4: appendFile(); break;
            case 5: printf("Exiting program.\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
