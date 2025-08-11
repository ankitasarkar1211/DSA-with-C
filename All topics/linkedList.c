#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>

struct node
{
  int data;
  struct node *next;
};
struct node *start=NULL;
struct node *createLL(struct node *start);
struct node *insert_beg(struct node *start);
struct node *insert_end(struct node *start);
struct node *insert_bef(struct node *start);
struct node *insert_aft(struct node *start);
struct node *delete_beg(struct node *start);
struct node *delete_end(struct node *start);
struct node *delete_node(struct node *start);
struct node *delete_aft(struct node *start);
struct node *delete_list(struct node *start);
struct node *sort_list(struct node *start);
struct node *display(struct node *start);

int main()
{
  int option;
  do
  {
    printf("\n*MAIN MENU*\n(1)Create Linked List\n(2)Insert at the beginning\n(3)Insert at the end\n(4)Insert before any node\n");
    printf("(5)Insert after any node\n(6)Delete fron beginning\n(7)Delete from end\n(8)Delete node\n(9)Delete after any node\n");
    printf("(10)Delete list\n(11)Sort list\n(12)Display list\n(13)Exit\n");
    printf("Enter opt: ");
    scanf("%d",&option);
    switch(option)
    {
      case 1:
      start=createLL(start);
      printf("Created LL");
      break;
      case 2:
      start=insert_beg(start);
      break;
      case 3:
      start=insert_end(start);
      break;
      case 4:
      start=insert_bef(start);
      break;
      case 5:
      start=insert_aft(start);
      break;
      case 6:
      start=delete_beg(start);
      break;
      case 7:
      start=delete_end(start);
      break;
      case 8:
      start=delete_node(start);
      break;
      case 9:
      start=delete_aft(start);
      break;
      case 10:
      start=delete_list(start);
      break;
      case 11:
      start=sort_list(start);
      break;
      case 12:
      start=display(start);
      break;
    }
  }while(option!=13);
  return 0;
}
struct node *createLL(struct node *start)
{
  struct node *ptr,*new_node;
  int num;
  printf("Enter -1 to end\n");
  printf("Enter number: ");
  scanf("%d",&num);
  while(num!=-1)
  {
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    if(start==NULL)
    {
      new_node->next=NULL;
      start=new_node;
    }
    else
    {
      ptr=start;
      while(ptr->next!=NULL)
      {
        ptr=ptr->next;
      }
      ptr->next=new_node;
      new_node->next=NULL;
    }
    printf("Enter number: ");
    scanf("%d",&num);
  }
  return start;
}
struct node *insert_beg(struct node *start)
{
  struct node *new_node;
  new_node=(struct node *)malloc(sizeof(struct node));
  int num;
  printf("Enter data: ");
  scanf("%d",&num);
  new_node->data=num;
  new_node->next=start;
  start=new_node;
  return start;
}
struct node *insert_end(struct node *start)
{
  struct node *new_node,*ptr;
  new_node=(struct node *)malloc(sizeof(struct node));
  int num;
  printf("Enter data: ");
  scanf("%d",&num);
  new_node->data=num;
  ptr=start;
  if(start==NULL)
  new_node->next=NULL;
  else
  {
    while(ptr->next!=NULL)
    {
      ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->next=NULL;
  }
  return start;
}
struct node *insert_bef(struct node *start)
{
  struct node *new_node,*ptr,*preptr;
  new_node=(struct node *)malloc(sizeof(struct node));
  int num,val;
  printf("Enter data: ");
  scanf("%d",&num);
  printf("Enter the value before which the data has to be inserted : ");
  scanf("%d", &val);
  new_node->data=num;
  ptr=start;
  while(ptr->data!=val)
  {
    preptr=ptr;
    ptr=ptr->next;
  }
  preptr->next=new_node;
  new_node->next=ptr;
  return start;
}
struct node *insert_aft(struct node *start)
{
  struct node *new_node,*ptr,*preptr;
  new_node=(struct node *)malloc(sizeof(struct node));
  int num,val;
  printf("Enter data: ");
  scanf("%d",&num);
  printf("Enter the value after which the data has to be inserted : ");
  scanf("%d", &val);
  new_node->data=num;
  ptr=start;
  preptr=ptr;
  while(preptr->data!=val)
  {
    preptr=ptr;
    ptr=ptr->next;
  }
  preptr->next=new_node;
  new_node->next=ptr;
  return start;
}
struct node *delete_beg(struct node *start)
{
  struct node *ptr;
  ptr=start;
  printf("Value deleted is %d\n", start->data);
  start=start->next;
  free(ptr);
  return start;
}
struct node *delete_end(struct node *start)
{
  struct node *ptr,*preptr;
  ptr=start;
  if(ptr->next==NULL)
  start=delete_beg(start);
  else
  {
    while(ptr->next!=NULL)
    {
      preptr=ptr;
      ptr=ptr->next;
    }
    preptr->next=NULL;
    printf("Value deleted is %d", ptr->data);
    free(ptr);
    return start;
  }
}
struct node *delete_node(struct node *start)
{
  struct node *ptr,*preptr;
  ptr=start;
  int val;
  printf("Enter value to be deleted: ");
  scanf("%d",&val);
  if(ptr->next==NULL)
  start=delete_beg(start);
  else
  {
    while(ptr->data!=val)
    {
      preptr=ptr;
      ptr=ptr->next;
    }
    preptr->next=ptr->next;
    printf("value deleted is %d",ptr->data);
    free(ptr);
  }
  return start;
}
struct node *delete_aft(struct node *start)
{
  struct node *ptr,*preptr;
  ptr=start;
  preptr=ptr;
  int val;
  printf("Enter value after which value to be deletet: ");
  scanf("%d",&val);
  if(ptr->next==NULL)
  start=delete_beg(start);
  else
  {
    while(preptr->data!=val)
    {
      preptr=ptr;
      ptr=ptr->next;
    }
    preptr->next=ptr->next;
    printf("value deleted is %d",ptr->data);
    free(ptr);
  }
  return start;
}
struct node *delete_list(struct node *start)
{
  struct node *ptr;
  ptr=start;
  while(ptr->next!=NULL)
  {
    start=delete_beg(start);
    ptr=ptr->next;
  }
  return start;
}
struct node *sort_list(struct node *start)
{
  struct node *ptr1,*ptr2;
  int swap;
  ptr1=start;
  while(ptr1->next!=NULL)
  {
    ptr2=ptr1->next;
    while(ptr2->next!=NULL)
    {
      if(ptr1->data>ptr2->data)
      {
        swap=ptr2->data;
        ptr2->data=ptr1->data;
        ptr1->data=swap;
      }
      ptr2=ptr2->next;
    }
    ptr1=ptr1->next;
  }
  return start;
}
struct node *display(struct node *start)
{
  struct node *ptr;
  ptr=start;
  while(ptr->next!=NULL)
  {
    printf("%d ", ptr->data);
    ptr=ptr->next;
  }
  printf("%d ",ptr->data);
  return start;
}