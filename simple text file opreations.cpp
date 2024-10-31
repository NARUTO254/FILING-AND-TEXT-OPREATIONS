#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeToFile(const char *filename) {
    FILE *fptr;
    char sentence[100];

    printf("Enter a sentence (up to 100 characters): ");
    fgets(sentence, 100, stdin);

    fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fptr, "%s", sentence);
    fclose(fptr);
    printf("Sentence written to file successfully!\n");
}

void readFromFile(const char *filename) {
    FILE *fptr;
    char ch;

    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("File contents:\n");
    while ((ch = fgetc(fptr)) != EOF) {
        putchar(ch);
    }

    fclose(fptr);
}

void appendToFile(const char *filename) {
    FILE *fptr;
    char sentence[100];

    printf("Enter a sentence to append: ");
    fgets(sentence, 100, stdin);

    fptr = fopen(filename, "a");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fptr, "%s", sentence);
    fclose(fptr);
    printf("Sentence appended to file successfully!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Write a sentence to the file\n");
        printf("2. Read the file contents\n");
        printf("3. Append a sentence to the file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                writeToFile("data.txt");
                break;
            case 2:
                readFromFile("data.txt");
                break;
            case 3:
                appendToFile("data.txt");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}