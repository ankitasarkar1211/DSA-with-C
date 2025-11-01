#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Search in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// Find minimum node (for deletion)
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Delete node from BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Find LCA in BST
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);
    if (n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);
    return root;
}

// Level order traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* curr = queue[front++];
        printf("%d ", curr->data);
        if (curr->left) queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }
}

int main() {
    struct Node* root = NULL;
    int choice, val, n, n1, n2;

    while (1) {
        printf("\n\n=== BST MENU ===\n");
        printf("1. Insert nodes\n");
        printf("2. Search a node\n");
        printf("3. Delete a node\n");
        printf("4. Find LCA\n");
        printf("5. Level Order Traversal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val))
                    printf("Node %d found.\n", val);
                else
                    printf("Node not found.\n");
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                printf("Updated Level Order: ");
                levelOrder(root);
                printf("\n");
                break;

            case 4:
                printf("Enter two node values: ");
                scanf("%d %d", &n1, &n2);
                {
                    struct Node* lca = findLCA(root, n1, n2);
                    if (lca)
                        printf("LCA of %d and %d is %d\n", n1, n2, lca->data);
                    else
                        printf("LCA not found.\n");
                }
                break;

            case 5:
                printf("Level Order Traversal: ");
                levelOrder(root);
                printf("\n");
                break;

            case 0:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
