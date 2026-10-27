/*
 * =================================================================================================
 * RESOLUÇÃO: Árvore Binária de Busca [7]
 * =================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Estrutura do Nó da Árvore */
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

/* Criação de um novo nó */
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Inserção (Valores iguais vão para a ESQUERDA) */
Node* insert(Node* root, int key) {
    if (root == NULL) return createNode(key);
    
    /* Chaves repetidas ou menores vão para a sub-árvore esquerda */
    if (key <= root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

/* Encontra o ANTECESSOR (Maior valor da sub-árvore esquerda) */
Node* maxValueNode(Node* node) {
    Node* current = node;
    /* Desce tudo para a direita para achar o maior valor */
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

/* Exclusão de Nó */
Node* deleteNode(Node* root, int key, int* deleted_flag) {
    Node* temp;
    int internal_flag;

    if (root == NULL) return root;

    /* Procura o nó a ser deletado */
    if (key < root->key) {
        root->left = deleteNode(root->left, key, deleted_flag);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key, deleted_flag);
    } else {
        /* Achou o nó a ser removido. Marca sucesso. */
        if (*deleted_flag == 0) {
            *deleted_flag = 1; 
        }

        /* Casos com um ou nenhum filho */
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        /* Caso com dois filhos: busca o ANTECESSOR na sub-árvore esquerda */
        temp = maxValueNode(root->left);
        
        /* Copia o valor do antecessor para o nó atual */
        root->key = temp->key;
        
        /* Remove o antecessor de sua posição original.
           A flag interna evita o print duplicado da exclusão. */
        internal_flag = 1; 
        root->left = deleteNode(root->left, temp->key, &internal_flag);
    }
    return root;
}

/* Funções de Percurso (Um por linha) */
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

/* Limpeza da Memória */
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    /* Declarações no topo do bloco para compatibilidade */
    Node* root = NULL;
    char cmd[20];
    int val;
    int deleted;

    while (scanf("%s", cmd) != EOF) {
        
        if (strcmp(cmd, "insert") == 0) {
            scanf("%d", &val);
            root = insert(root, val);
            
        } else if (strcmp(cmd, "delete") == 0) {
            scanf("%d", &val);
            deleted = 0;
            root = deleteNode(root, val, &deleted);
            
            if (deleted) {
                printf("%d\n", val);
            }
            
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