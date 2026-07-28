#include <stdio.h>
#include <stdlib.h>

// Função para imprimir o vetor inteiro
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", arr[i]);
    }
    printf("\n");
}

// Função que intercala (Merge) dois subvetores
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Cria vetores temporários
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copia os dados para os vetores temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Intercala os vetores temporários de volta para arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Função principal do Merge Sort que divide o vetor
void mergeSort(int arr[], int l, int r, int n) {
    if (l < r) {
        // Encontra o ponto médio
        int m = l + (r - l) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, l, m, n);
        mergeSort(arr, m + 1, r, n);

        // Imprime sempre a situação do vetor ANTES de efetuar uma intercalação [cite: 182, 190]
        printArray(arr, n);

        // Intercala as metades ordenadas
        merge(arr, l, m, r);
    }
}

int main() {
    int n;

    // Lê o tamanho do vetor
    if (scanf("%d", &n) != 1) return 0;

    // Se o vetor for vazio (N=0), apenas encerra
    if (n == 0) {
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));

    // Lê os elementos
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Imprime o vetor original 
    printArray(arr, n);

    // Inicia o algoritmo de Merge Sort
    mergeSort(arr, 0, n - 1, n);

    // Imprime o vetor após o término da ordenação 
    printArray(arr, n);

    free(arr);
    return 0;
}