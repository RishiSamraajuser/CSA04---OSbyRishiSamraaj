#include <stdio.h>
#include <stdlib.h>

// Structure to represent an employee
struct Employee {
    int id;
    char name[50];
    float salary;
};

// Function to add a new employee record to the file
void addEmployee(FILE *file) {
    struct Employee newEmployee;

    printf("Enter Employee ID: ");
    scanf("%d", &newEmployee.id);

    printf("Enter Employee Name: ");
    scanf("%s", newEmployee.name);

    printf("Enter Employee Salary: ");
    scanf("%f", &newEmployee.salary);

    // Move the file pointer to the end of the file
    fseek(file, 0, SEEK_END);

    // Write the new employee record to the file
    fwrite(&newEmployee, sizeof(struct Employee), 1, file);

    printf("Employee added successfully.\n");
}

// Function to display all employee records from the file
void displayEmployees(FILE *file) {
    struct Employee currentEmployee;

    // Move the file pointer to the beginning of the file
    fseek(file, 0, SEEK_SET);

    printf("\nEmployee Details:\n");

    // Read and display each employee record from the file
    while (fread(&currentEmployee, sizeof(struct Employee), 1, file) == 1) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", currentEmployee.id, currentEmployee.name, currentEmployee.salary);
    }
}

// Function to update employee details based on ID
void updateEmployee(FILE *file, int targetID) {
    struct Employee updatedEmployee;

    // Move the file pointer to the beginning of the file
    fseek(file, 0, SEEK_SET);

    int found = 0;

    // Search for the target employee ID
    while (fread(&updatedEmployee, sizeof(struct Employee), 1, file) == 1) {
        if (updatedEmployee.id == targetID) {
            found = 1;

            // Move the file pointer back by the size of an employee record
            fseek(file, -sizeof(struct Employee), SEEK_CUR);

            // Update the employee details
            printf("Enter updated Employee Name: ");
            scanf("%s", updatedEmployee.name);

            printf("Enter updated Employee Salary: ");
            scanf("%f", &updatedEmployee.salary);

            // Write the updated employee record to the file
            fwrite(&updatedEmployee, sizeof(struct Employee), 1, file);

            printf("Employee details updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", targetID);
    }
}

int main() {
    FILE *employeeFile;

    // Open or create the employee data file in binary mode
    employeeFile = fopen("employee_data.dat", "ab+");

    if (employeeFile == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    int choice;
    int targetID;

    do {
        printf("\nEmployee Management System:\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Update Employee Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employeeFile);
                break;
            case 2:
                displayEmployees(employeeFile);
                break;
            case 3:
                printf("Enter Employee ID to update: ");
                scanf("%d", &targetID);
                updateEmployee(employeeFile, targetID);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    // Close the file before exiting the program
    fclose(employeeFile);

    return 0;
}
