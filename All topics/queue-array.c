#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 5
int a[max],front=-1,rear=-1;
void insert(int a[],int val);
void delete(int a[],int val);
void peek(int a[]);
void display(int a[]);
int main()
{
  int option,val;
  do{
    printf("*MAIN MENU*\n(1)Insertion\n(2)Deletion\n(3)Peek\n(4)Display\n(5)Exit\n");
    printf("Enter a option: ");
    scanf("%d",&option);
    switch(option)
    {
      case 1:
      printf("Enter the no. that you want to insert: ");
      scanf("%d",&val);
      insert(a,val);
      break;
      case 2:
      delete(a,val);
      break;
      case 3:
      peek(a);
      break;
      case 4:
      display(a);
    }
  }while(option!=5);
}
void insert(int a[],int val)
{
  if(rear == max - 1)
    printf("Overflow\n");
  else if(front == -1 && rear == -1)
  {
    front = rear = 0;
    a[rear] = val;
  }
  else
  {
    rear++;
    a[rear] = val;
  }
}
void delete(int a[],int val)
{
  if(front==-1 || front>rear)
  printf("Underflow\n");
  else{
    val=a[front];
    front++;
    printf("Value deleted is %d\n",val);
  }
}
void peek(int a[])
{
  if(front==-1 || front>rear)
  printf("Empty Stack\n");
  else{
    printf("First element is %d\n",a[front]);
  }
}
void display(int a[])
{
  int i;
  if(front==-1 || front>rear)
  printf("Empty stack\n");
  printf("The array is: \n");
  for(i=front;i<=rear;i++)
  {
    printf("%d ",a[i]);
  }
  printf("\n");
}