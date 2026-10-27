/*
 * =================================================================================================
 * RESOLUÇÃO: Árvore Binária de Busca
 * =================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 1. Estrutura do Nó da Árvore */
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

/* 2. Criação de um novo nó */
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* 3. Inserção (Com regra de repetidos à direita) */
Node* insert(Node* root, int key) {
    if (root == NULL) return createNode(key);
    
    /* Regra do PDF: Chaves repetidas ou maiores vão para a direita */
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

/* 4. Encontra o sucessor (Menor valor da sub-árvore direita) */
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

/* 5. Exclusão de Nó */
Node* deleteNode(Node* root, int key, int* deleted_flag) {
    Node* temp;
    int internal_flag;

    /* Ignora a exclusão se o nó não existir na árvore */
    if (root == NULL) return root;

    /* Navega na árvore procurando o valor */
    if (key < root->key) {
        root->left = deleteNode(root->left, key, deleted_flag);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key, deleted_flag);
    } else {
        /* Achou o nó a ser excluído */
        if (*deleted_flag == 0) {
            *deleted_flag = 1; /* Marca que a exclusão foi um sucesso */
        }

        /* Caso 1 e 2: Nó com apenas um filho ou nenhum filho */
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        /* Caso 3: Nó com dois filhos. Busca o sucessor. */
        temp = minValueNode(root->right);
        
        /* Copia o valor do sucessor para o nó atual */
        root->key = temp->key;
        
        /* Remove o sucessor de sua posição original.
           A flag interna garante que não vamos dar print duplo acidentalmente. */
        internal_flag = 1; 
        root->right = deleteNode(root->right, temp->key, &internal_flag);
    }
    return root;
}

/* 6. Percursos (Pré-ordem, Em Ordem e Pós-ordem) */
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

/* 7. Limpeza da Memória ao finalizar */
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    /* Variáveis declaradas no início para padrão C89 */
    Node* root = NULL;
    char cmd[20];
    int val;
    int deleted;

    /* Lê comandos enquanto não houver Fim de Arquivo (EOF) */
    while (scanf("%s", cmd) != EOF) {
        
        if (strcmp(cmd, "insert") == 0) {
            scanf("%d", &val);
            root = insert(root, val);
            
        } else if (strcmp(cmd, "delete") == 0) {
            scanf("%d", &val);
            deleted = 0;
            root = deleteNode(root, val, &deleted);
            
            /* A cada operação de exclusão BEM SUCEDIDA mostre o valor na tela */
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