#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store task details
struct Task {
    int taskId;              // Unique ID of the task
    char description[200];   // Description of the task
    int priority;            // Priority (higher number = higher priority)
    struct Task *next;       // Pointer to the next task
};

// Function prototypes
void addTask(struct Task **head, int taskId, char description[], int priority);
void deleteTask(struct Task **head, int taskId);
void displayTasks(struct Task *head);
void prioritizeTasks(struct Task **head);
int searchTask(struct Task *head, int taskId);

// Function to add a new task
void addTask(struct Task **head, int taskId, char description[], int priority) {
    struct Task *newTask = (struct Task *)malloc(sizeof(struct Task));
    if (!newTask) {
        printf("Memory allocation failed.\n");
        return;
    }
    newTask->taskId = taskId;
    strcpy(newTask->description, description);
    newTask->priority = priority;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        struct Task *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newTask;
    }
    printf("Task with ID %d added successfully.\n", taskId);
}

// Function to delete a task by ID
void deleteTask(struct Task **head, int taskId) {
    if (*head == NULL) {
        printf("No tasks to delete.\n");
        return;
    }

    struct Task *temp = *head;
    struct Task *prev = NULL;

    if (temp != NULL && temp->taskId == taskId) {
        *head = temp->next;
        free(temp);
        printf("Task with ID %d deleted successfully.\n", taskId);
        return;
    }

    while (temp != NULL && temp->taskId != taskId) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Task with ID %d not found.\n", taskId);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Task with ID %d deleted successfully.\n", taskId);
}

// Function to display all tasks
void displayTasks(struct Task *head) {
    if (head == NULL) {
        printf("No tasks in the list.\n");
        return;
    }
    printf("\n--- Task List ---\n");
    struct Task *temp = head;
    while (temp != NULL) {
        printf("ID: %d | Priority: %d | Description: %s\n",
               temp->taskId, temp->priority, temp->description);
        temp = temp->next;
    }
}

// Function to sort tasks based on priority (Descending)
void prioritizeTasks(struct Task **head) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("Not enough tasks to prioritize.\n");
        return;
    }

    struct Task *i, *j;
    int tempId, tempPriority;
    char tempDesc[200];

    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (j->priority > i->priority) {
                // Swap task data
                tempId = i->taskId;
                i->taskId = j->taskId;
                j->taskId = tempId;

                strcpy(tempDesc, i->description);
                strcpy(i->description, j->description);
                strcpy(j->description, tempDesc);

                tempPriority = i->priority;
                i->priority = j->priority;
                j->priority = tempPriority;
            }
        }
    }
    printf("Tasks prioritized successfully.\n");
}

// Function to search task by ID
int searchTask(struct Task *head, int taskId) {
    int index = 0;
    struct Task *temp = head;
    while (temp != NULL) {
        if (temp->taskId == taskId)
            return index;
        temp = temp->next;
        index++;
    }
    return -1; // Not found
}

// Main menu-driven function
int main() {
    struct Task *head = NULL;
    int choice, taskId, priority, pos;
    char description[200];

    while (1) {
        printf("\n--- Task Manager Menu ---\n");
        printf("1. Add a task\n");
        printf("2. Delete a task\n");
        printf("3. Display all tasks\n");
        printf("4. Prioritize tasks\n");
        printf("5. Search for a task\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline from buffer

        switch (choice) {
            case 1:
                printf("Enter Task ID: ");
                scanf("%d", &taskId);
                getchar();

                printf("Enter Task Description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0';

                printf("Enter Priority (higher number = higher priority): ");
                scanf("%d", &priority);

                addTask(&head, taskId, description, priority);
                break;

            case 2:
                printf("Enter Task ID to delete: ");
                scanf("%d", &taskId);
                deleteTask(&head, taskId);
                break;

            case 3:
                displayTasks(head);
                break;

            case 4:
                prioritizeTasks(&head);
                break;

            case 5:
                printf("Enter Task ID to search: ");
                scanf("%d", &taskId);
                pos = searchTask(head, taskId);
                if (pos != -1)
                    printf("Task with ID %d found at position %d.\n", taskId, pos);
                else
                    printf("Task with ID %d not found.\n", taskId);
                break;

            case 6:
                printf("Exiting program...\n");
                while (head != NULL) {
                    struct Task *temp = head;
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
