#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student details
struct Student {
    char name[100];          // Student name
    int rollNumber;          // Roll number
    float marks;             // Marks obtained
    struct Student *next;    // Pointer to the next student
};

// Global head pointer for the linked list
struct Student *head = NULL;

// Function prototypes
void addStudent(char name[], int rollNumber, float marks);
void deleteStudent(int rollNumber);
void displayStudents();
int searchStudent(int rollNumber);

// Function to add a new student
void addStudent(char name[], int rollNumber, float marks) {
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    if (!newStudent) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(newStudent->name, name);
    newStudent->rollNumber = rollNumber;
    newStudent->marks = marks;
    newStudent->next = NULL;

    if (head == NULL) {
        head = newStudent;
    } else {
        struct Student *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newStudent;
    }
    printf("Student %s (Roll No: %d) added successfully.\n", name, rollNumber);
}

// Function to delete a student by roll number
void deleteStudent(int rollNumber) {
    if (head == NULL) {
        printf("No records to delete.\n");
        return;
    }

    struct Student *temp = head;
    struct Student *prev = NULL;

    if (temp != NULL && temp->rollNumber == rollNumber) {
        head = temp->next;
        free(temp);
        printf("Student with Roll No %d deleted successfully.\n", rollNumber);
        return;
    }

    while (temp != NULL && temp->rollNumber != rollNumber) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with Roll No %d not found.\n", rollNumber);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Student with Roll No %d deleted successfully.\n", rollNumber);
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {
        printf("No student records found.\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    struct Student *temp = head;
    while (temp != NULL) {
        printf("Name: %s | Roll No: %d | Marks: %.2f\n",
               temp->name, temp->rollNumber, temp->marks);
        temp = temp->next;
    }
}

// Function to search for a student by roll number
int searchStudent(int rollNumber) {
    int index = 0;
    struct Student *temp = head;
    while (temp != NULL) {
        if (temp->rollNumber == rollNumber)
            return index;
        temp = temp->next;
        index++;
    }
    return -1; // Not found
}

// Main menu-driven program
int main() {
    int choice, rollNumber, pos;
    float marks;
    char name[100];

    while (1) {
        printf("\n--- Student Record Management ---\n");
        printf("1. Add a student record\n");
        printf("2. Delete a student record\n");
        printf("3. Display all student records\n");
        printf("4. Search for a student record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                printf("Enter Roll Number: ");
                scanf("%d", &rollNumber);

                printf("Enter Marks: ");
                scanf("%f", &marks);

                addStudent(name, rollNumber, marks);
                break;

            case 2:
                printf("Enter Roll Number to delete: ");
                scanf("%d", &rollNumber);
                deleteStudent(rollNumber);
                break;

            case 3:
                displayStudents();
                break;

            case 4:
                printf("Enter Roll Number to search: ");
                scanf("%d", &rollNumber);
                pos = searchStudent(rollNumber);
                if (pos != -1)
                    printf("Student found at position %d.\n", pos);
                else
                    printf("Student not found.\n");
                break;

            case 5:
                printf("Exiting program...\n");
                while (head != NULL) {
                    struct Student *temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
