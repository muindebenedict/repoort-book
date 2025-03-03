// File: src/main.c
#include <stdio.h>
#include "report.h"

int main() {
    Student students[MAX_STUDENTS];
    int count = 0, choice;

    loadFromFile(students, &count);

    while (1) {
        printf("\nReport Book System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                saveToFile(students, count);
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

