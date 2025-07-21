#include <stdio.h>
#include <stdlib.h>
#define size 5

int arr[size];
void input();
void insert(int value);
int search(int value);
void delete(int value);
void printAll();

struct node{
  int data;
  struct node *next;
};

struct node *chain[size];

int main(){
  int num,find,searching,del;
  input();

  printf("Enter %d values:\n", size);
  for(int i = 0; i < size; i++){
    scanf("%d", &num);
    insert(num);
  } 

  printf("Enter a number to search:\n");
  scanf("%d",&find);
  searching=search(find);
  if(searching)
    printf("found\n");
  else
    printf("Not found\n");

  printf("All the elements are: \n");
  printAll();

  printf("Enter a element to delete: ");
  scanf("%d",&del);
  delete(del);

  printf("After deletion: \n");
  printAll();

  return 0;
}

void input(){
  for(int i=0;i<size;i++)
    chain[i]=NULL;
}

void insert(int value){
  struct node *new_node;
  new_node=(struct node*)malloc(sizeof(struct node));
  new_node->data=value;
  new_node->next=NULL;
  
  int key=value%size;
  if(chain[key]==NULL){
    chain[key]=new_node;
  }
  else{
    struct node *temp=chain[key];
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=new_node;
  }
}

int search(int value){
  int key=value%size;
  struct node *temp=chain[key];
  while(temp){
    if(temp->data==value)
      return 1;
  }
  return 0;
}

void delete(int value){
  int key = value % size;
  struct node *temp = chain[key];
  struct node *prev = NULL;

  while (temp != NULL) {
    if (temp->data == value) {
      if (prev == NULL) {
        chain[key] = temp->next;
      } else {
        prev->next = temp->next;
      }
      free(temp);
      printf("Element %d deleted.\n", value);
      return;
    }
    prev = temp;
    temp = temp->next;
  }
  printf("Element %d not found.\n", value);
}

void printAll(){
  for(int i=0;i<size;i++){
    struct node *temp=chain[i];
    printf("chain[%d]->",i);
    while(temp){  //do not write while(temp->next!=NULL)
      printf("%d ",temp->data);
      temp=temp->next;
    }
    printf("NULL\n");
  }
}