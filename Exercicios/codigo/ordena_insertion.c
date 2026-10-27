#include <stdio.h>

void imprimeVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", v[i]);
    }
    printf("\n");
}

int main() {
    int n;
    
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    int v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    // 1. Imprime o vetor original
    imprimeVetor(v, n);

    int trocas = 0;

    // 2. Insertion Sort com impressão a cada troca
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && v[j] < v[j - 1]) {
            int temp = v[j];
            v[j] = v[j - 1];
            v[j - 1] = temp;
            
            trocas++;
            imprimeVetor(v, n);
            j--;
        }
    }

    // 3. Imprime o vetor ordenado (antepenúltima linha)
    imprimeVetor(v, n);

    // 4. Imprime a quantidade de trocas
    printf("Trocas: %d\n", trocas);

    // 5. Imprime o caso e pula a linha final exigida diretamente na string
    int max_trocas = (n * (n - 1)) / 2;
    
    if (trocas == 0) {
        printf("MELHOR CASO\n");
    } else if (trocas == max_trocas) {
        printf("PIOR CASO\n");
    } else {
        printf("CASO ALEATORIO\n");
    }

    return 0;
}