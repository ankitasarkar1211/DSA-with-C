#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 3
int a[max],TOP=-1;
void push(int a[],int val);
void pop(int a[],int val);
void peek(int a[]);
void display(int a[]);

int main()
{
  int val,option;
  do{
    printf("*MAIN MENU*\n");
    printf("(1)Push\n(2)Pop\n(3)Peek\n(4)Display\n(5)Exit\n");
    printf("Choose a option: ");
    scanf("%d",&option);

    switch(option)
    {
      case 1:
      printf("Enter a no. that you want to insert: ");
      scanf("%d",&val);
      push(a,val);
      break;
      case 2:
      pop(a,val);
      break;
      case 3:
      peek(a);
      break;
      case 4:
      display(a);
      break;
      
    } 
  }while(option!=5);

  return 0;
}
void push(int a[],int val)
{
  if(TOP==max-1)
  printf("Overflow\n");
  else
  {
    TOP++;
    a[TOP]=val;
  }
}
void pop(int a[],int val)
{
  if(TOP==-1)
  printf("Underflow\n");
  else{
    val=a[TOP];
    TOP--;
    printf("Value deleted is %d\n",val);
  }
}
void peek(int a[])
{
  if(TOP==-1)
  printf("Empty stack\n");
  else{
    printf("Value on top is %d\n",a[TOP]);
  }
}
void display(int a[])
{
  int i;
  if(TOP==-1)
  printf("Empty stack\n");
  else{
    for(i=TOP;i>-1;i--)
    {
      printf("%d ",a[i]);
    }
  }
}