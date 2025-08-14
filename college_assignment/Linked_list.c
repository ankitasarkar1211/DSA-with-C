#include <stdio.h> 
#include <stdlib.h>

struct node { 
	int data; 
	struct node* next;
};

void insertNode(struct node** head, int value); 
void deleteNode(struct node** head, int value); 
void displayList(struct node* head); 
void reverseList(struct node** head); 
int searchNode(struct node* head, int value);

int main() {
	struct node* head = NULL; 
	int choice, value, result;

	while (1) {
		printf("\n--- Linked List Menu ---\n");
		printf("1. Insert a node at the end of the list\n");
		printf("2. Delete a node by value\n");
		printf("3. Display the list\n");
		printf("4. Reverse the list\n");
		printf("5. Search for a node\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
		    case 1:
		        printf("Enter value to insert: ");
		        scanf("%d", &value);
		        insertNode(&head, value);
		        break;
		    case 2:
		        printf("Enter value to delete: ");
		        scanf("%d", &value);
		        deleteNode(&head, value);
		        break;
		    case 3:
		        displayList(head);
		        break;
		    case 4:
		        reverseList(&head);
		        break;
		    case 5:
		        printf("Enter value to search: ");
		        scanf("%d", &value);
		        result = searchNode(head, value);
		        if (result != -1)
		            printf("Value found at position: %d\n", result);
		        else
		            printf("Value not found in the list.\n");
		        break;
		    case 6:
		        printf("Exiting program.\n");
		        exit(0);
		    default:
		        printf("Invalid choice. Try again.\n");
		}
	}

	return 0;
}

void insertNode(struct node** head, int value) { 
	struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
	newNode->data = value; 
	newNode->next = NULL;

	if (*head == NULL) {
		*head = newNode;
	} else {
		struct node* temp = *head;
		while (temp->next != NULL)
		    temp = temp->next;
		temp->next = newNode;
	}
	printf("Node inserted.\n");
}

void deleteNode(struct node** head, int value) { 
	if (*head == NULL) { 
		printf("List is empty.\n"); 
		return; 
	} 

	struct node* temp = *head; 
	struct node* prev = NULL;

	if (temp->data == value) {
		*head = temp->next;
		free(temp);
		printf("Node deleted.\n");
		return;
	}

	while (temp != NULL && temp->data != value) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) {
		printf("Value not found.\n");
		return;
	}

	prev->next = temp->next;
	free(temp);
	printf("Node deleted.\n");
}

void displayList(struct node* head) { 
	if (head == NULL) { 
		printf("List is empty.\n"); 
		return; 
	} 
	struct node* temp = head; 
	printf("List elements: "); 
	while (temp != NULL) { 
		printf("%d ", temp->data); 
		temp = temp->next;
	} 
	printf("\n"); 
}

void reverseList(struct node** head) { 
	struct node *prev = NULL, *ptr = *head, *next_node;
	while (ptr != NULL) { 
    next_node=ptr->next;
    ptr->next=prev;
    prev=ptr;
    ptr=next_node;
	}
	*head = prev; 
	printf("List reversed.\n");
}

int searchNode(struct node* head, int value) {
	if (head == NULL) {
		printf("Linked list Empty\n");
		return -1;
	}

	struct node *temp = head;
	int pos = 1;

	while (temp != NULL) {
		if (temp->data == value) {
			return pos;
		}
		temp = temp->next;
		pos++;
	}
	return -1; // Not found
}