#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct node{
  char data;
  struct node *next;
};

void push(struct node **top, char val);
int pop(struct node **top);
bool isParentheses(char str[100]);

int isEmpty(struct node *top) {
  return top==NULL;
}

int main() {
  char str[100];
  printf("Enter string of parentheses to check: ");
  fgets(str,sizeof(str),stdin);
  str[strcspn(str,"\n")]='\0';

  if(isParentheses(str))
    printf("Balanced");
  else
    printf("Not Balanced");

  return 0;
}
void push(struct node **top, char val) {
  struct node *new_node=(struct node*)malloc(sizeof(struct node));
  new_node->data=val;
  if(isEmpty(*top)) {
    new_node->next=NULL;
    *top=new_node;
    return;
  } 
  new_node->next=*top;
  *top=new_node;
}
int pop(struct node **top) {
  struct node *temp=*top;
  int poppedValue=temp->data;
  *top=temp->next;
  free(temp);
  return poppedValue;
}
bool isParentheses( char str[100]) {
  struct node *top=NULL;
  for(int i=0;i<strlen(str);i++) {
    if(str[i]=='(' || str[i]=='[' || str[i]=='{') {
      push(&top,str[i]);
    }
    else if(str[i]==')' || str[i]==']' || str[i]=='}') {
      if(isEmpty(top)) return false;  //no opening brackets

      char topchar=pop(&top);
      if(str[i]==')' && topchar!='('  ||  str[i]==']' && topchar!='['  || str[i]=='}' && topchar!='{')
        return false;
    }
  }
  if(isEmpty(top)) return true;

  return false;
}