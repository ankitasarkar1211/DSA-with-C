#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next; 
};

void insert(int num);
void display();

struct node *head=NULL;

int main() {
  int num;
  printf("Enter 3 elements:\n");
  for(int i=0;i<3;i++){
    scanf("%d",&num);
    insert(num);
  }
  display();

  return 0;
}
void insert(int num) {
  struct node *new_node;
  new_node=(struct node*)malloc(sizeof(struct node));
  new_node->data=num;
  new_node->next=NULL;

  if(head==NULL){
    head=new_node;
  }
  else {
    new_node->next=head;
    head=new_node;
  }
}

void display() {
  struct node *ptr=head;
  printf("The elements in the Linked List are: ");
  while(ptr!=NULL) {
    printf("%d ",ptr->data);
    ptr=ptr->next;
  }
}
