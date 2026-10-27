#include <stdio.h>
#include <stdlib.h>

// Tabela de pesos: o índice do vetor é o dígito impresso, 
// o valor dentro do vetor é a sua verdadeira "força" marciana.
int peso_marciano[10] = {0, 8, 9, 7, 3, 1, 2, 6, 4, 5};

// Estrutura para não perdermos o número original após a tradução
typedef struct {
    int original;
    int valor_convertido;
} NumeroMarciano;

// Função que traduz um número da Terra para a sua magnitude em Marte
int calcularValorMarciano(int num) {
    if (num == 0) return 0; // O zero é igual em ambos os planetas

    int convertido = 0;
    int multiplicador = 1; // Unidade, dezena, centena, etc.
    int temp = num;

    while (temp > 0) {
        int digito = temp % 10; // Extrai o último algarismo
        
        // Adiciona o peso daquele algarismo na posição correta
        convertido += peso_marciano[digito] * multiplicador; 
        
        multiplicador *= 10; // Passa para a próxima casa decimal
        temp /= 10;          // Remove o último algarismo
    }

    return convertido;
}

// Função para ensinar o qsort a ordenar pela magnitude marciana
int comparar(const void *a, const void *b) {
    NumeroMarciano *numA = (NumeroMarciano *)a;
    NumeroMarciano *numB = (NumeroMarciano *)b;
    
    return numA->valor_convertido - numB->valor_convertido;
}

int main() {
    int n;

    // Lê a quantidade de números
    if (scanf("%d", &n) != 1) return 0;

    // Aloca a memória dinamicamente
    NumeroMarciano *numeros = (NumeroMarciano *)malloc(n * sizeof(NumeroMarciano));

    // Lê os números e já calcula o seu peso marciano
    for (int i = 0; i < n; i++) {
        scanf("%d", &numeros[i].original);
        numeros[i].valor_convertido = calcularValorMarciano(numeros[i].original);
    }

    // Ordena o vetor usando o valor_convertido
    qsort(numeros, n, sizeof(NumeroMarciano), comparar);

    // Imprime os números originais separados por espaço (sem espaço no fim)
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", numeros[i].original);
    }
    printf("\n"); // Salto de linha exigido ao final

    free(numeros);

    return 0;
}