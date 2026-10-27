#include <stdio.h>
// 1. TESTEEEEEEEEEE

int main() {
    int n;

    if (scanf("%d", &n) != 1) return 0;

    int L[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &L[i]);
    }

    for (int i = 1; i <= n; i++) {
        
        // 1. Imprime a Sublista Ordenada
        printf("Sublista Ordenada:");
        for (int j = 0; j < i; j++) {
            printf(" %d", L[j]);
        }
        printf("\n"); 

        // 2. Imprime a Sublista Desordenada
        printf("Sublista Desordenada:");
        for (int j = i; j < n; j++) {
            printf(" %d", L[j]);
        }
        
        // CORREÇÃO: Apenas um \n para pular a linha, sem criar linha em branco dupla
        printf("\n"); 

        // 3. Executa a Lógica do Insertion Sort
        if (i < n) {
            int chave = L[i];
            int j = i - 1;

            while (j >= 0 && L[j] > chave) {
                L[j + 1] = L[j];
                j--;
            }
            L[j + 1] = chave;
        }
    }

    return 0;
}