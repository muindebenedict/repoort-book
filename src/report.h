// File: include/report.h
#ifndef REPORT_H
#define REPORT_H

#define MAX_STUDENTS 100 // Maximum students that can be stored

// Structure to hold student data
typedef struct {
    char name[50];
    int roll_no;
    float marks[5]; // Assuming 5 subjects
    float average;
} Student;

// Function prototypes
void addStudent(Student students[], int *count);
void displayStudents(Student students[], int count);
void calculateAverage(Student *student);
void saveToFile(Student students[], int count);
void loadFromFile(Student students[], int *count);

#endif
