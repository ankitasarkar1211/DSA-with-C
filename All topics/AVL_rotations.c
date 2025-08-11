#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left,*right;
    int height;
};

int height(struct node *n) {
    if (n==NULL)
        return 0;
    return n->height;
}

int max(int a,int b) {
    return (a > b)?a:b;
}

struct node* newnode(int key) {
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->key=key;
    new_node->left=new_node->right = NULL;
    new_node->height=1;
    return new_node;
}

int getBalance(struct node *n) {
    if (n==NULL)
        return 0;
    return height(n->left)-height(n->right);
}

//LL rotation
struct node* rightRotate(struct node *y) {
    struct node* x=y->left;
    struct node* temp=x->right;

    x->right=y;
    y->left=temp;

    y->height=max(height(y->left), height(y->right)) + 1;
    x->height=max(height(x->left), height(x->right)) + 1;

    return x;
}

//RR rotation
struct node* leftRotate(struct node* x) {
    struct node* y=x->right;
    struct node* temp=y->left;

    y->left=x;
    x->right=temp;

    x->height=max(height(x->left), height(x->right))+1;
    y->height=max(height(y->left), height(y->right))+1;

    return y;
}

struct node* insert(struct node* node, int key) {
    if (node==NULL)
        return newnode(key);

    if (key < node->key)
        node->left=insert(node->left, key);
    else if (key>node->key)
        node->right=insert(node->right, key);
    else
        return node;

    node->height = 1+max(height(node->left),height(node->right));
    int balance=getBalance(node);

    // LL
    if (balance>1 && key<node->left->key)
        return rightRotate(node);

    // RR
    if (balance<-1 && key>node->right->key)
        return leftRotate(node);

    // LR
    if (balance>1 && key>node->left->key) {
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (balance<-1 && key<node->right->key) {
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int n, val;

    printf("Enter no. of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n", n);

    for (int i=0;i<n;i++) {
        scanf("%d",&val);
        root=insert(root, val);
    }

    printf("Preorder traversal of AVL tree:\n");
    preOrder(root);
    return 0;
}