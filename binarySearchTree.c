#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *create_node(int val);
struct node *insert(struct node *root, int val);
struct node *search(struct node *root, int key);

int main() {
  struct node *root = NULL;
  struct node *result;
  int i, n, val, key;
  
  printf("Enter no. of elements: ");
  scanf("%d", &n);
  
  printf("Enter %d elements:\n", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &val);
    root = insert(root, val);
  }

  printf("Enter the element to be searched: ");
  scanf("%d", &key);
  result = search(root, key);

  if (result != NULL)
    printf("%d found in BST", key);
  else
    printf("%d not found in BST", key);

  return 0;
}

struct node *create_node(int val) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = val;
  new_node->left = new_node->right = NULL;
  return new_node;
}

struct node *insert(struct node *root, int val) {
  if (root == NULL)
    return create_node(val);
  if (val < root->data)
    root->left = insert(root->left, val);
  else
    root->right = insert(root->right, val);
  return root;
}

struct node *search(struct node *root, int key) {
  if (root == NULL || root->data == key)
    return root;
  if (key < root->data)
    return search(root->left, key);
  else
    return search(root->right, key);
}