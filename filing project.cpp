#include <stdio.h>

int main() {
    FILE *fptr;
    char name[50];
    int marks;
    int i;

    fptr = fopen("students.txt", "w"); // Open the file in write mode

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (i = 0; i < 5; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", name);

        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks);

        fprintf(fptr, "%s %d\n", name, marks); // Write to the file
    }

    fclose(fptr); // Close the file

    printf("Data written to file successfully!\n");

    return 0;
}