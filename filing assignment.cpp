#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    float marks;
};

int main() {
    struct Student students[5];
    int i;
    FILE *fptr;

    // Input student information
    for (i = 0; i < 5; i++) {
        printf("Enter details of student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No.: ");
        scanf("%d", &students[i].roll_no);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    // Write student data to file
    fptr = fopen("students.bin", "wb");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fwrite(students, sizeof(struct Student), 5, fptr);
    fclose(fptr);

    // Read student data from file
    fptr = fopen("students.bin", "rb");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fread(students, sizeof(struct Student), 5, fptr);
    fclose(fptr);

    // Display student information
    printf("\nStudent Information:\n");
    for (i = 0; i < 5; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Roll No.: %d\n", students[i].roll_no);
        printf("Marks: %.2f\n\n", students[i].marks);
    }

    return 0;
}