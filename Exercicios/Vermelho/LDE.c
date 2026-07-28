#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

void inserir(No **cabeca, int valor) {
    No *atual = *cabeca;
    No *anterior = NULL;
    while (atual != NULL && atual->valor < valor) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual != NULL && atual->valor == valor) return;
    
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = atual;
    
    if (anterior == NULL) *cabeca = novo;
    else anterior->prox = novo;
}

void remover(No **cabeca, int valor) {
    No *atual = *cabeca;
    No *anterior = NULL;
    while (atual != NULL && atual->valor < valor) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL || atual->valor != valor) return;
    
    if (anterior == NULL) *cabeca = atual->prox;
    else anterior->prox = atual->prox;
    free(atual);
}

void buscar(No *cabeca, int valor) {
    No *atual = cabeca;
    while (atual != NULL && atual->valor <= valor) {
        if (atual->valor == valor) {
            printf("SIM\n");
            return;
        }
        atual = atual->prox;
    }
    printf("NAO\n");
}

void mostrar(No *cabeca) {
    // CORREÇÃO: Se estiver vazio, não imprime linha em branco extra
    if (cabeca == NULL) return; 
    
    No *atual = cabeca;
    int primeiro = 1;
    while (atual != NULL) {
        if (!primeiro) printf(" ");
        printf("%d", atual->valor);
        primeiro = 0;
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    No *cabeca = NULL;
    char operacao;
    int valor;
    
    while (scanf(" %c", &operacao) != EOF) {
        if (operacao == 'I') {
            scanf("%d", &valor);
            inserir(&cabeca, valor);
        } else if (operacao == 'R') {
            scanf("%d", &valor);
            remover(&cabeca, valor);
        } else if (operacao == 'B') {
            scanf("%d", &valor);
            buscar(cabeca, valor);
        } else if (operacao == 'L') {
            mostrar(cabeca);
        }
    }
    
    No *atual = cabeca;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    return 0;
}