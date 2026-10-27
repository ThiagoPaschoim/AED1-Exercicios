#include <stdio.h>

int main() {
    int n;

    // Lê o comprimento da lista L (1 <= N <= 1000)
    if (scanf("%d", &n) != 1) return 0;

    int L[n];

    // Lê os elementos da lista
    for (int i = 0; i < n; i++) {
        scanf("%d", &L[i]);
    }

    // Variável para armazenar a quantidade total de movimentos
    int movimentos = 0;

    // Lógica clássica do Insertion Sort
    for (int i = 1; i < n; i++) {
        int chave = L[i];
        int j = i - 1;

        // O laço while procura a posição correta e "empurra" os maiores para a direita
        while (j >= 0 && L[j] > chave) {
            L[j + 1] = L[j]; // Movimenta o elemento para a direita
            movimentos++;    // <- CONTA O MOVIMENTO AQUI
            j--;
        }
        L[j + 1] = chave; // Insere a chave na posição correta (isso não conta como movimento no enunciado)
    }

    // A saída consiste apenas no número de movimentos, seguido da quebra de linha
    printf("%d\n", movimentos);

    return 0;
}