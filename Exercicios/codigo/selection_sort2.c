#include <stdio.h>

// Função que implementa a Ordenação por Seleção em ordem decrescente
void selectionSortDecrescente(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Assume que o maior elemento está na posição atual 'i'
        int indice_maior = i;
        
        // Procura se existe alguém maior no resto do vetor
        for (int j = i + 1; j < n; j++) {
            // A principal mudança está aqui: verificamos se é MAIOR (>)
            if (v[j] > v[indice_maior]) { 
                indice_maior = j;
            }
        }
        
        // Troca o elemento atual com o maior elemento encontrado
        if (indice_maior != i) {
            int temp = v[i];
            v[i] = v[indice_maior];
            v[indice_maior] = temp;
        }
    }
}

int main() {
    int n;
    
    // O programa terá vários casos de teste[cite: 120].
    // A entrada termina quando N=0[cite: 126].
    while (scanf("%d", &n) == 1 && n != 0) {
        int v[n];
        
        // Lê os elementos do vetor, que cabem em um int padrão[cite: 124, 125].
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }
        
        // Chama a função para ordenar
        selectionSortDecrescente(v, n);
        
        // Mostra o vetor ordenado resultante, cada valor separado por um espaço em branco, exceto o último[cite: 129, 130].
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                printf(" ");
            }
            printf("%d", v[i]);
        }
        
        // Após a impressão do último vetor ordenado salte uma linha[cite: 131].
        printf("\n"); 
    }
    
    return 0;
}