#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

void enqueue(struct node **top1, struct node **top2,int val);
void dequeue(struct node **top1, struct node **top2);
void display(struct node *top1);

int empty(struct node *top1) {
  return top1==NULL;
}
void push(struct node **top2, int val) {
  struct node *new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=val;
  new_node->next=NULL;
  if(*top2==NULL) *top2=new_node;
  else {
    new_node->next=*top2;
    *top2=new_node;
  }
}

int main() {
  struct node *top1=NULL, *top2=NULL;
  enqueue(&top1,&top2,10);
  enqueue(&top1,&top2,20);
  enqueue(&top1,&top2,30);
  enqueue(&top1,&top2,40);
  printf("After enqueue:\n");
  display(top1);

  dequeue(&top1,&top2);
  dequeue(&top1,&top2);
  printf("After denqueue:\n");
  display(top1);

  return 0;
}
void enqueue(struct node **top1, struct node **top2,int val) {
  struct node *new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=val;
  new_node->next=NULL;
  if(empty(*top1))  *top1=new_node;
  else {
    while(*top1!=NULL) {
      push(&top2,(*top1)->data);
      (*top1)=(*top1)->next;
    }
    push(&top1,val);
    while(*top2!=NULL) {
      push(&top1,(*top2)->data);
      (*top2)=(*top2)->next;
    }
  }  
}
void display(struct node *top1) {
  struct node *temp=top1;
  while(temp!=NULL) {
    printf("%d ",temp->data);
    temp=temp->next;
  }
}