#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char name[50];
    int marks, n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    fptr = fopen("students.txt", "a+"); // Open the file in append+ mode

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", name);

        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks);

        fprintf(fptr, "%s %d\n", name, marks); // Append to the file
    }

    fclose(fptr); // Close the file

    printf("Data written to file successfully!\n");

    return 0;
}