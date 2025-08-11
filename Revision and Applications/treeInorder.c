#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int val);
struct node *insert(struct node *root,int val);
void *display(struct node *root);

int main() {
  struct node *root=NULL;
  int n,val,i;

  printf("Enter no. of elements: ");
  scanf("%d", &n);
  
  printf("Enter %d elements:\n", n);
  for (i=0;i<n;i++) {
    scanf("%d", &val);
    root = insert(root,val);
  }
  printf("The tree in In-order traversal are: ");
  display(root);

  return 0;
}
struct node *createNode(int val) {
  struct node *new_node;
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->data=val;
  new_node->left=NULL;
  new_node->right=NULL;

  return new_node;
}
struct node *insert(struct node *root,int val) {
  if(root==NULL) {
    return createNode(val);
  }
  else if(val<root->data) {
    root->left=insert(root->left,val);
  }
  else {
    root->right=insert(root->right,val);
  }
}
void *display(struct node *root) {
  
  if(root!=NULL){
    display(root->left);
    printf("%d ",root->data);
    display(root->right);
  }
}