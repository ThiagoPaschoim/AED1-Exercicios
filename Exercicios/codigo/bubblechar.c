#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para imprimir o vetor formatado
void imprimeVetor(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", arr[i]);
        // Garante que não há espaço impresso após o último elemento
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int n;
    
    // Lê o tamanho do vetor
    if (scanf("%d", &n) != 1) return 0;

    // Aloca dinamicamente o vetor de caracteres
    char *arr = (char *)malloc(n * sizeof(char));
    if (arr == NULL) return 1;

    // Lê os elementos do vetor
    for (int i = 0; i < n; i++) {
        // O espaço antes do %c é crucial! Ele instrui o C a ignorar 
        // quaisquer espaços em branco ou quebras de linha anteriores.
        scanf(" %c", &arr[i]); 
    }

    // 1. A primeira linha: o vetor na sua ordem original
    imprimeVetor(arr, n);

    int trocas = 0;

    // 2. Algoritmo Bubble Sort Clássico
    // O laço externo controla quantas passagens faremos
    for (int i = 0; i < n - 1; i++) {
        // O laço interno faz as comparações adjacentes.
        // A cada iteração 'i', o maior elemento já foi para o final,
        // por isso subtraímos 'i' do limite.
        for (int j = 0; j < n - 1 - i; j++) {
            // Comparação lexicográfica crescente (tabela ASCII)
            if (arr[j] > arr[j + 1]) {
                // Realiza a troca
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                trocas++;

                // Imprime o vetor imediatamente após a troca
                imprimeVetor(arr, n);
            }
        }
    }

    // 3. A penúltima linha: vetor ordenado
    imprimeVetor(arr, n);

    // 4. A última linha: quantidade de trocas
    printf("Trocas: %d\n", trocas);

    // Libera a memória alocada
    free(arr);

    return 0;
}