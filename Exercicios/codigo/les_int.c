#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int *les, int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (les[meio] == valor) return meio;
        else if (les[meio] < valor) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

void inserir(int *les, int *tamanho, int capacidade, int valor) {
    if (*tamanho >= capacidade) return;
    if (buscaBinaria(les, *tamanho, valor) != -1) return;
    
    int i = *tamanho - 1;
    while (i >= 0 && les[i] > valor) {
        les[i + 1] = les[i];
        i--;
    }
    les[i + 1] = valor;
    (*tamanho)++;
}

void remover(int *les, int *tamanho, int valor) {
    int indice = buscaBinaria(les, *tamanho, valor);
    if (indice == -1) return;
    for (int i = indice; i < *tamanho - 1; i++) {
        les[i] = les[i + 1];
    }
    (*tamanho)--;
}

void mostrar(int *les, int tamanho) {
    // CORREÇÃO: Se estiver vazio, não imprime a linha em branco que irrita o BOCA
    if (tamanho == 0) return; 
    
    for (int i = 0; i < tamanho; i++) {
        if (i > 0) printf(" ");
        printf("%d", les[i]);
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    int *les = (int *)malloc(n * sizeof(int));
    int tamanho_atual = 0;
    char operacao;
    int valor;
    
    while (scanf(" %c", &operacao) != EOF) {
        if (operacao == 'I') {
            scanf("%d", &valor);
            inserir(les, &tamanho_atual, n, valor);
        } else if (operacao == 'R') {
            scanf("%d", &valor);
            remover(les, &tamanho_atual, valor);
        } else if (operacao == 'B') {
            scanf("%d", &valor);
            if (buscaBinaria(les, tamanho_atual, valor) != -1) printf("SIM\n");
            else printf("NAO\n");
        } else if (operacao == 'M') {
            mostrar(les, tamanho_atual);
        }
    }
    free(les);
    return 0;
}