#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Create binary tree (user input)
struct Node* createBinaryTree() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    struct Node* root = createNode(data);
    printf("Enter left child of %d\n", data);
    root->left = createBinaryTree();
    printf("Enter right child of %d\n", data);
    root->right = createBinaryTree();

    return root;
}

// Height
int height(struct Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

// Check balanced
bool isBalanced(struct Node* root) {
    if (root == NULL) return true;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
}

// Check BST
bool isBSTUtil(struct Node* root, int min, int max) {
    if (root == NULL) return true;
    if (root->data < min || root->data > max)
        return false;
    return isBSTUtil(root->left, min, root->data - 1) &&
           isBSTUtil(root->right, root->data + 1, max);
}

bool isBST(struct Node* root) {
    return isBSTUtil(root, -10000, 10000);
}

// Diameter
int diameterUtil(struct Node* root, int *height) {
    if (root == NULL) {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ldiameter = diameterUtil(root->left, &lh);
    int rdiameter = diameterUtil(root->right, &rh);
    *height = (lh > rh ? lh : rh) + 1;

    int currDiameter = lh + rh + 1;
    if (ldiameter > currDiameter)
        currDiameter = ldiameter;
    if (rdiameter > currDiameter)
        currDiameter = rdiameter;
    return currDiameter;
}

int diameter(struct Node* root) {
    int height = 0;
    return diameterUtil(root, &height);
}

int main() {
    struct Node* root = NULL;

    printf("Create Binary Tree:\n");
    root = createBinaryTree();

    printf("\nIs the tree balanced? %s\n", isBalanced(root) ? "Yes" : "No");
    printf("Is it a Binary Search Tree? %s\n", isBST(root) ? "Yes" : "No");
    printf("Diameter of the Binary Tree: %d\n", diameter(root));

    return 0;
}
