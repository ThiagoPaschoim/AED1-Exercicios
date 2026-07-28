#include <stdio.h>
#include <string.h>

// Função auxiliar para imprimir o vetor de strings com espaços
void imprimeVetor(int n, char v[][105]) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" "); // Imprime espaço apenas entre as strings
        }
        printf("%s", v[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Lê o tamanho do vetor (0 < N <= 200)
    if (scanf("%d", &n) != 1) return 0;

    // Declara uma matriz de carateres (um vetor de N strings, cada uma com tamanho até 105)
    char v[n][105];

    // Lê as strings
    for (int i = 0; i < n; i++) {
        scanf("%s", v[i]);
    }

    // 1. Imprime a primeira linha: o vetor na sua ordem original
    imprimeVetor(n, v);

    int trocas = 0;

    // 2. Lógica do Bubble Sort para Strings
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            
            // strcmp devolve um número > 0 se a primeira string for "maior" que a segunda
            if (strcmp(v[j], v[j + 1]) > 0) {
                
                // Efetua a troca de posições usando strcpy
                char temp[105];
                strcpy(temp, v[j]);
                strcpy(v[j], v[j + 1]);
                strcpy(v[j + 1], temp);
                
                trocas++;
                
                // Imprime todo o vetor a cada troca efetuada
                imprimeVetor(n, v);
            }
        }
    }

// 3. Imprime a penúltima linha: vetor completamente ordenado
    imprimeVetor(n, v);

    // 4. Imprime a contagem de trocas (O \n aqui já é o salto de linha final)
    printf("Trocas: %d\n", trocas);

    return 0;
}