#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct queue {
  struct node *front;
  struct node *rear;
};

struct queue *create();
struct queue *insert(struct queue *q, int val);
struct queue *delete(struct queue *q);
void display(struct queue *q);
void peek(struct queue *q);

int main() {
  int option, val;
  struct queue *q = create();

  do {
    printf("\nMAIN MENU\n");
    printf("(1) Push\n(2) Pop\n(3) Peek\n(4) Display\n(5) Exit\n");
    printf("Choose an option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Enter number to insert: ");
        scanf("%d", &val);
        q = insert(q, val);
        break;
      case 2:
        q = delete(q);
        break;
      case 3:
        peek(q);
        break;
      case 4:
        display(q);
        break;
    }
  } while (option != 5);

  return 0;
}

struct queue *create() {
  struct queue *q = (struct queue *)malloc(sizeof(struct queue));
  q->front = NULL;
  q->rear = NULL;
  return q;
}

struct queue *insert(struct queue *q, int val) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  ptr->data = val;
  ptr->next = NULL;

  if (q->front == NULL) {
    q->front = ptr;
    q->rear = ptr;
  } else {
    q->rear->next = ptr;
    q->rear = ptr;
  }
  return q;
}

struct queue *delete(struct queue *q) {
  if (q->front == NULL) {
    printf("Underflow\n");
    return q;
  }

  struct node *ptr = q->front;
  printf("The value being deleted is: %d\n", ptr->data);
  q->front = q->front->next;
  free(ptr);

  if (q->front == NULL)
    q->rear = NULL;

  return q;
}

void display(struct queue *q) {
  if (q->front == NULL) {
    printf("Queue is empty\n");
    return;
  }

  struct node *ptr = q->front;
  printf("Queue elements: ");
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

void peek(struct queue *q) {
  if (q->front == NULL) {
    printf("Underflow\n");
  } else {
    printf("Front value is: %d\n", q->front->data);
  }
}