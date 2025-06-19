#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>

struct stack 
{
  int data;
  struct stack *next;
};
struct stack *top=NULL;
struct stack *push(struct stack *top,int val);
struct stack *pop(struct stack *top,int val);
struct stack *display(struct stack *top);
void peek(struct stack *top);

int main()
{
  int option,val;
  do 
  {
    printf("*MAIN MENU*\n");
    printf("(1)Push\n(2)Pop\n(3)Peek\n(4)Display\n(5)Exit\n");
    printf("Choose a option: ");
    scanf("%d",&option);
    switch(option)
    {
      case 1:
      printf("Enter no. to insert: ");
      scanf("%d",&val);
      top=push(top,val);
      break;
      case 2:
      top=pop(top,val);
      break;
      case 3:
      peek(top);
      break;
      case 4:
      display(top);
      break;
    }
  }while(option!=5);

  return 0;
}
struct stack *push(struct stack *top,int val)
{
  struct stack *ptr;
  ptr=(struct stack*)malloc(sizeof(struct stack));
  ptr->data=val;
  if(top==NULL)
  ptr->next=NULL;
  else
  ptr->next=top;

  top=ptr;
}
struct stack *pop(struct stack *top,int val)
{
  struct stack *ptr;
  ptr=top;
  if(top==NULL)
  printf("Stack Underflow");
  else
  {
    val=ptr->data;
    printf("Value deleted: %d",val);
    top=top->next;
  }
}
void peek(struct stack *top)
{
  struct stack *ptr;
  ptr=top;
  if(top==NULL)
  printf("Stack Empty");
  else
  {
    printf("Value on top: %d",ptr->data);
  }
}
struct stack *display(struct stack *top)
{
  struct stack *ptr;
  ptr=top;
  if(top==NULL)
  printf("Stack Empty");
  else
  {
    while(ptr!=NULL)
    {
      printf("%d ",ptr->data);
      ptr=ptr->next;
    }
  }
}