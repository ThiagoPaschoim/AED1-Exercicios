#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == NULL) return createNode(key);
    if (key <= root->key) root->left = insert(root->left, key); /* Repetidos na Esquerda */
    else root->right = insert(root->right, key); 
    return root;
}

Node* extractMin(Node* root, Node** extracted) {
    if (root->left == NULL) {
        *extracted = root;
        return root->right;
    }
    root->left = extractMin(root->left, extracted);
    return root;
}

Node* deleteNode(Node* root, int key, int* deleted_flag) {
    Node* temp;
    Node* extracted = NULL;
    if (root == NULL) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key, deleted_flag);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key, deleted_flag);
    } else {
        if (*deleted_flag == 0) *deleted_flag = 1; 

        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        /* Sucessor */
        root->right = extractMin(root->right, &extracted);
        root->key = extracted->key;
        free(extracted);
    }
    return root;
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d\n", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d\n", root->key);
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\n", root->key);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    char cmd[20];
    int val, deleted;

    while (scanf("%s", cmd) != EOF) {
        if (strcmp(cmd, "insert") == 0) {
            scanf("%d", &val);
            root = insert(root, val);
        } else if (strcmp(cmd, "delete") == 0) {
            scanf("%d", &val);
            deleted = 0;
            root = deleteNode(root, val, &deleted);
            if (deleted) printf("%d\n", val);
        } else if (strcmp(cmd, "pre-order") == 0) {
            preOrder(root);
        } else if (strcmp(cmd, "in-order") == 0) {
            inOrder(root);
        } else if (strcmp(cmd, "post-order") == 0) {
            postOrder(root);
        }
    }
    freeTree(root);
    return 0;
}