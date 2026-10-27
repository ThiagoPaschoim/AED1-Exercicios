#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para imprimir o vetor formatado
void imprimeVetor(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        // Garante que não há espaço impresso após o último elemento 
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int n;
    
    // Lê o tamanho do vetor [cite: 8]
    if (scanf("%d", &n) != 1) return 0;

    // Aloca dinamicamente o vetor
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) return 1;

    // Lê os elementos do vetor [cite: 9]
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 1. A primeira linha da saída: o vetor na sua ordem original [cite: 13]
    imprimeVetor(arr, n);

    int trocas = 0;

    // 2. Insertion Sort adaptado: a cada troca, imprime o vetor [cite: 14]
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            
            trocas++;

            // Imprime o vetor a cada troca realizada [cite: 14]
            imprimeVetor(arr, n);

            j--;
        }
    }

    // 3. A antepenúltima linha: vetor ordenado [cite: 15]
    imprimeVetor(arr, n);

    // 4. A penúltima linha: quantidade de trocas [cite: 16]
    printf("Trocas: %d\n", trocas);

    // 5. A última linha: classificação do caso [cite: 17]
    int max_trocas = (n * (n - 1)) / 2;
    
    if (trocas == 0) {
        printf("MELHOR CASO\n"); // Apenas um \n aqui atende a quebra de linha final 
    } else if (trocas == max_trocas) {
        printf("PIOR CASO\n");
    } else {
        printf("CASO ALEATORIO\n");
    }

    // Libera a memória alocada
    free(arr);

    return 0;
}