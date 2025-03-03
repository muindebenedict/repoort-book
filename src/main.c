#include <stdio.h>
#include <stdlib.h>
#include "report.h" // Include the header file for function declarations

int main() {
    int choice;
    
    while (1) {
        // Display menu
        printf("\n===== Report Book System =====\n");
        printf("1. Add Student Report\n");
        printf("2. Display Reports\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Handle user choice
        switch (choice) {
            case 1:
                addReport(); // Function to add a report
                break;
            case 2:
                displayReports(); // Function to display reports
                break;
            case 3:
                printf("Exiting the program...\n");
                exit(0); // Exit the program
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
