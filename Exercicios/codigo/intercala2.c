#include <stdio.h>
#include <stdlib.h> // Para malloc e free

int main() {
    int q1, q2;

    // Lê as quantidades
    if (scanf("%d", &q1) != 1) return 0;
    if (scanf("%d", &q2) != 1) return 0;

    int tamanho_total = q1 + q2;

    // Aloca o vetor principal (Vu) e o vetor auxiliar (Vaux)
    int *Vu = (int *)malloc(tamanho_total * sizeof(int));
    int *Vaux = (int *)malloc(tamanho_total * sizeof(int));

    // Carrega os q1 valores na primeira parte do vetor Vu
    for (int i = 0; i < q1; i++) {
        scanf("%d", &Vu[i]);
    }

    // Carrega os q2 valores na segunda parte do vetor Vu (começando do índice q1)
    for (int i = 0; i < q2; i++) {
        scanf("%d", &Vu[q1 + i]);
    }

    // Intercalação usando o vetor auxiliar
    int i = 0;          // Ponteiro para a primeira metade
    int j = q1;         // Ponteiro para a segunda metade
    int k = 0;          // Ponteiro para o vetor auxiliar

    while (i < q1 && j < tamanho_total) {
        if (Vu[i] <= Vu[j]) {
            Vaux[k] = Vu[i];
            i++;
        } else {
            Vaux[k] = Vu[j];
            j++;
        }
        k++;
    }

    // Copia o que sobrou da primeira metade (se houver)
    while (i < q1) {
        Vaux[k] = Vu[i];
        i++;
        k++;
    }

    // Copia o que sobrou da segunda metade (se houver)
    while (j < tamanho_total) {
        Vaux[k] = Vu[j];
        j++;
        k++;
    }

    // Reconstroi o Vu copiando do auxiliar e já imprime a saída
    for (int x = 0; x < tamanho_total; x++) {
        Vu[x] = Vaux[x];
        printf("%d\n", Vu[x]);
    }

    // Libera a memória alocada
    free(Vu);
    free(Vaux);

    return 0;
}