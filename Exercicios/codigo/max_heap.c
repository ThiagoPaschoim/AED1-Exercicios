#include <stdio.h>

// Função auxiliar para trocar dois valores
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função que "afunda" um nó se ele for menor que os seus filhos
void maxHeapify(int arr[], int n, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    // Se o filho da esquerda for maior que a raiz
    if (esquerda < n && arr[esquerda] > arr[maior]) {
        maior = esquerda;
    }

    // Se o filho da direita for maior que o maior até agora
    if (direita < n && arr[direita] > arr[maior]) {
        maior = direita;
    }

    // Se o maior não for a raiz, faz a troca e continua a verificar para baixo
    if (maior != i) {
        swap(&arr[i], &arr[maior]);
        maxHeapify(arr, n, maior);
    }
}

// Função principal que constrói o Max Heap
void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

int main() {
    int n;
    // Declaração estática para evitar erros de VLA (Variable Length Array) no BOCA
    int arr[105]; 

    // Continua a ler até N ser 0
    while (scanf("%d", &n) == 1 && n != 0) {
        
        // Lê os elementos do vetor
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        // Transforma o vetor num Max Heap
        buildMaxHeap(arr, n);

        // Imprime o vetor resultante com espaços, exceto antes do primeiro
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                printf(" ");
            }
            printf("%d", arr[i]);
        }
        printf("\n");
    }

    return 0;
}