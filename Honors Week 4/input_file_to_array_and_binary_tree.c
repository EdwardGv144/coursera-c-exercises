#include <stdio.h>
#include <stdlib.h>

// Binary tree node structure
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Create a new binary tree node
TreeNode *createNode(int value) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a value into the binary tree
TreeNode *insert(TreeNode *root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// In-order traversal
void inorderTraversal(TreeNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Free all nodes in the tree
void freeTree(TreeNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    FILE *file;
    int arraySize = 0;
    int *data;
    TreeNode *root = NULL;

    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    if (fscanf(file, "%d", &arraySize) != 1 || arraySize <= 0) {
        printf("Invalid or missing array size in file.\n");
        fclose(file);
        return 1;
    }

    data = (int *)malloc(arraySize * sizeof(int));
    if (data == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < arraySize; i++) {
        if (fscanf(file, "%d", &data[i]) != 1) {
            printf("Not enough integers for the specified array size.\n");
            free(data);
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    printf("Array of integers:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", data[i]);
        root = insert(root, data[i]);
    }

    printf("\nInorder traversal of the binary tree:\n");
    inorderTraversal(root);
    printf("\n");

    free(data);
    freeTree(root);

    return 0;
}
