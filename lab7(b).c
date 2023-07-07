#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;


typedef struct queue {
    Node *data;
    struct queue *next;
} Queue;


Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}


Queue *createQueue(Node *node) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->data = node;
    q->next = NULL;
    return q;
}


void enQueue(Queue **queue, Node *node) {
    Queue *q = createQueue(node);
    if (*queue == NULL) {
        *queue = q;
    } else {
        Queue *temp = *queue;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = q;
    }
}


Node *deQueue(Queue **queue) {
    if (*queue == NULL) {
        return NULL;
    }
    Queue *temp = *queue;
    Node *node = temp->data;
    *queue = temp->next;
    free(temp);
    return node;
}

void printBFS(Node* root) {
    Queue *q = NULL;
    enQueue(&q, root);
    while(q) {
        Node *node = deQueue(&q);
        printf("%d ", node->data);
        if (node->left != NULL) {
            enQueue(&q, node->left);
        }
        if (node->right != NULL) {
            enQueue(&q, node->right);
        }
    }
    printf("\n");
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

    printf("Breadth-First Search traversal:\n");
    printBFS(root);

    return 0;
}
