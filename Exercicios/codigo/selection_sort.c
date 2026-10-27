#include <stdio.h>

// Função que implementa a Ordenação por Seleção
void selectionSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Assume que o menor elemento está na posição atual 'i'
        int indice_menor = i;
        
        // Procura se existe alguém menor no resto do vetor
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[indice_menor]) {
                indice_menor = j;
            }
        }
        
        // Troca o elemento atual com o menor elemento encontrado
        if (indice_menor != i) {
            int temp = v[i];
            v[i] = v[indice_menor];
            v[indice_menor] = temp;
        }
    }
}

int main() {
    int n;
    
    // O laço lê o tamanho 'n'. Se a leitura for bem-sucedida e 'n' for diferente de 0, ele executa.
    while (scanf("%d", &n) == 1 && n != 0) {
        int v[n];
        
        // Lê os elementos do vetor
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }
        
        // Chama a função para ordenar
        selectionSort(v, n);
        
        // Imprime o vetor ordenado
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                printf(" "); // Imprime espaço antes do número, exceto no primeiro
            }
            printf("%d", v[i]);
        }
        printf("\n"); // Salta a linha após imprimir o vetor inteiro
    }
    
    return 0;
}