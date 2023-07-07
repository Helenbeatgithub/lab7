#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Preorder traversal
void printPreorder(Node* node) {
    if (node == NULL)
        return;

    printf("%d ", node->data);  // Visit the root
    printPreorder(node->left);  // Traverse left subtree
    printPreorder(node->right); // Traverse right subtree
}

// Inorder traversal
void printInorder(Node* node) {
    if (node == NULL)
        return;

    printInorder(node->left);  // Traverse left subtree
    printf("%d ", node->data); // Visit the root
    printInorder(node->right); // Traverse right subtree
}

// Postorder traversal
void printPostorder(Node* node) {
    if (node == NULL)
        return;

    printPostorder(node->left); // Traverse left subtree
    printPostorder(node->right); // Traverse right subtree
    printf("%d ", node->data); // Visit the root
}

int main() {
    Node *root = newNode(1);

    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right = newNode(5);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);

    root->right = newNode(3);
    root->right->left = newNode(6);
    root->right->left->left = newNode(12);
    root->right->left->right = newNode(13);
    root->right->right = newNode(7);
    root->right->right->left = newNode(14);
    root->right->right->right = newNode(15);
    
    printf("Preorder traversal :\n");
    printPreorder(root);

    printf("\nInorder traversal :\n");
    printInorder(root);

    printf("\nPostorder traversal :\n");
    printPostorder(root);

    return 0;
}