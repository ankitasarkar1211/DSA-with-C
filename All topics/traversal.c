#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};
struct node *create_node(int val);
struct node *insert(struct node *root,int val);
void *inOrder(struct node *root);
void *preOrder(struct node *root);
void *postOrder(struct node *root);

int main()
{
  struct node *root=NULL;
  int i,val,n;
  printf("Enter the no. of elements: ");
  scanf("%d",&n);
  printf("Enter %d elements:\n",n);
  for(i=0;i<n;i++){
    scanf("%d",&val);
    root=insert(root,val);
  }
  printf("In-order traversal:\n");
  inOrder(root);
  printf("\nPre-order traversal:\n");
  preOrder(root);
  printf("\nPost-order traversal:\n");
  postOrder(root);

  return 0;
}
struct node *create_node(int val){
  struct node *new;
  new=(struct node *)malloc(sizeof(struct node));
  new->data=val;
  new->left=new->right=NULL;
  return new;
}
struct node *insert(struct node *root,int val){
  if(root==NULL){
    root=create_node(val);
    return root;
  }
  if(val<root->data){
    root->left=insert(root->left,val);
    return root;
  }
  if(val>root->data){
    root->right=insert(root->right,val);
    return root;
  }
}
void *inOrder(struct node *root){
  if(root!=NULL){
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
  }
}
void *preOrder(struct node *root){
  if(root!=NULL){
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}
void *postOrder(struct node *root){
  if(root!=NULL){
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
  }
}
