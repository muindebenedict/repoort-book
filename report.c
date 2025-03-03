// File: src/report.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "report.h"

// Function to add a new student
void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student limit reached!\n");
        return;
    }

    printf("Enter student name: ");
    scanf(" %[^\n]", students[*count].name);
    printf("Enter roll number: ");
    scanf("%d", &students[*count].roll_no);

    printf("Enter marks for 5 subjects: ");
    for (int i = 0; i < 5; i++) {
        scanf("%f", &students[*count].marks[i]);
    }

    calculateAverage(&students[*count]);
    (*count)++;
}

// Function to calculate and store the average marks of a student
void calculateAverage(Student *student) {
    float sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += student->marks[i];
    }
    student->average = sum / 5;
}

// Function to display student details
void displayStudents(Student students[], int count) {
    printf("\nStudent Report Book:\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].roll_no);
        printf("Marks: ");
        for (int j = 0; j < 5; j++) {
            printf("%.2f ", students[i].marks[j]);
        }
        printf("\nAverage: %.2f\n", students[i].average);
        printf("-------------------------------------------------\n");
    }
}

// Function to save students' data to a file
void saveToFile(Student students[], int count) {
    FILE *file = fopen("students.txt", "w");
    if (!file) {
        printf("Error saving to file!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), count, file);
    fclose(file);
    printf("Data saved successfully.\n");
}

// Function to load students' data from a file
void loadFromFile(Student students[], int *count) {
    FILE *file = fopen("students.txt", "r");
    if (!file) {
        printf("No saved data found.\n");
        return;
    }

    fread(count, sizeof(int), 1, file);
    fread(students, sizeof(Student), *count, file);
    fclose(file);
    printf("Data loaded successfully.\n");
}
