#include <stdio.h>
#include <stdlib.h>

// 1. Criamos um "molde" (struct) para guardar todas as informações de um carro juntas
typedef struct {
    int nc;         // Número do carro
    char p[45];     // Nome do piloto (tamanho máximo 40 + margem)
    char e[45];     // Nome da equipe (tamanho máximo 40 + margem)
    double t;       // Tempo de qualificação
} Carro;

// 2. Função de comparação que ensina o qsort a ordenar pelo tempo (crescente)
int comparar(const void *a, const void *b) {
    Carro *carroA = (Carro *)a;
    Carro *carroB = (Carro *)b;

    // Se o tempo de A for menor, A vem primeiro (-1)
    if (carroA->t < carroB->t) return -1;
    // Se o tempo de A for maior, B vem primeiro (1)
    if (carroA->t > carroB->t) return 1;
    // (O problema garante que não há tempos iguais, então não precisamos de desempate)
    return 0;
}

int main() {
    int n;

    // Lê a quantidade de carros
    if (scanf("%d", &n) != 1) return 0;

    // Alocação dinâmica para aguentar até 100.000 carros sem dar erro de memória
    Carro *carros = (Carro *)malloc(n * sizeof(Carro));

    // Lê as informações de todos os carros
    for (int i = 0; i < n; i++) {
        // %lf é usado para ler variável do tipo double
        scanf("%d %s %s %lf", &carros[i].nc, carros[i].p, carros[i].e, &carros[i].t);
    }

    int k;
    // Lê a posição desejada pelo diretor de prova
    scanf("%d", &k);

    // 3. A Mágica: Ordena o vetor inteiro quase instantaneamente
    qsort(carros, n, sizeof(Carro), comparar);

    // 4. Imprime o carro que ficou na posição K
    // Como os vetores em C começam no 0, a posição K está no índice K - 1.
    printf("%d %s %s\n", carros[k - 1].nc, carros[k - 1].p, carros[k - 1].e);

    // Libera a memória usada
    free(carros);

    return 0;
}