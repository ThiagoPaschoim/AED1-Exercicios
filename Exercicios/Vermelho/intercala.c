#include <stdio.h>
#include <stdlib.h> // Necessário para usar o malloc e free

int main() {
    int q1, q2;

    // Lê os tamanhos dos dois vetores
    if (scanf("%d", &q1) != 1) return 0;
    if (scanf("%d", &q2) != 1) return 0;

    // Alocação dinâmica de memória para suportar vetores gigantes (até 500.000)
    int *v1 = (int *)malloc(q1 * sizeof(int));
    int *v2 = (int *)malloc(q2 * sizeof(int));
    int *vr = (int *)malloc((q1 + q2) * sizeof(int));

    // Lê os elementos do primeiro vetor
    for (int i = 0; i < q1; i++) {
        scanf("%d", &v1[i]);
    }

    // Lê os elementos do segundo vetor
    for (int i = 0; i < q2; i++) {
        scanf("%d", &v2[i]);
    }

    // Técnica dos Dois Ponteiros para intercalação em O(n)
    int i = 0; // Índice para v1
    int j = 0; // Índice para v2
    int k = 0; // Índice para vr (Vetor Resultante)

    while (i < q1 && j < q2) {
        if (v1[i] <= v2[j]) {
            vr[k] = v1[i];
            i++;
        } else {
            vr[k] = v2[j];
            j++;
        }
        k++;
    }

    // Se o vetor 2 acabou antes, copia todo o restante do vetor 1
    while (i < q1) {
        vr[k] = v1[i];
        i++;
        k++;
    }

    // Se o vetor 1 acabou antes, copia todo o restante do vetor 2
    while (j < q2) {
        vr[k] = v2[j];
        j++;
        k++;
    }

    // Imprime o vetor resultante ordenado (um por linha, conforme o exemplo)
    for (int x = 0; x < (q1 + q2); x++) {
        printf("%d\n", vr[x]);
    }

    // Boa prática em C: sempre liberar a memória que foi alocada dinamicamente
    free(v1);
    free(v2);
    free(vr);

    return 0;
}