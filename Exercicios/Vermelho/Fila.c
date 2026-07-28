#include <stdio.h>
#include <stdlib.h>

/* =================================================================================================
 * ENUNCIADO DO PROBLEMA: FILA ESTÁTICA (Fila)
 * =================================================================================================
 * Faça um programa que implemente uma Fila Estática conforme o padrão de entrada a seguir:
 * * ENTRADA:
 * O programa receberá como entrada um número natural N, 0 < N <= 1000,
 * representando o tamanho da fila. Em seguida haverá uma sucessão de comandos:
 * E <valor> : Inclusão do Valor na Fila
 * D         : Exclusão do Valor na Fila (Deve imprimir o valor removido)
 * * * RESTRIÇÕES:
 * - Caso a operação tente incluir um valor em uma Fila Cheia ou excluir de uma
 * Fila Vazia a operação deve ser ignorada.
 * - A entrada termina com EOF.
 * - E após excluir o último elemento da Fila, faça com que a fila volte ao estado de fila vazia.
 * * * SAÍDA:
 * A cada operação de exclusão (D), o valor desenfileirado deve ser exibido.
 * Após a impressão de cada valor, salte uma linha.
 * =================================================================================================
 */

/* =================================================================================================
 * GUIA DE ESTUDO: A ESTRUTURA FILA E COMO ALTERÁ-LA NA PROVA
 * =================================================================================================
 * O que são as variáveis 'inicio' e 'fim'?
 * Diferente da Pilha (que só tem o 'topo'), a Fila precisa de duas marcações:
 * - 'inicio': aponta para o índice do elemento que será removido (o primeiro da fila).
 * - 'fim': aponta para o próximo índice vazio onde o novo elemento será inserido.
 * * A Fila está VAZIA quando: inicio == fim
 * A Fila está CHEIA quando: fim == capacidade máxima
 * * Como alterar na prova:
 * Se o professor pedir para mostrar a fila inteira sem remover, você faria um laço:
 * for (int i = inicio; i < fim; i++) { printf("%d ", fila[i]); }
 */

// 1. ENFILEIRAR (ENQUEUE / INSERIR)
void enfileirar(int *fila, int *fim, int capacidade, int valor) {
    // Verifica se a fila está cheia (o 'fim' bateu no limite do vetor)
    if (*fim >= capacidade) {
        return;
    }
    
    // Insere o valor no final da fila e incrementa o índice do fim
    fila[*fim] = valor;
    (*fim)++;
}

// 2. DESENFILEIRAR (DEQUEUE / REMOVER)
void desenfileirar(int *fila, int *inicio, int *fim) {
    // Verifica se a fila está vazia (início alcançou o fim)
    if (*inicio == *fim) {
        return;
    }
    
    // Pega o valor que está no início da fila
    int valor_removido = fila[*inicio];
    
    // "Remove" o valor andando com o índice do início para a direita
    (*inicio)++;
    
    // Imprime o valor removido conforme exigido pelo BOCA
    printf("%d\n", valor_removido);
    
    // REGRA DE OURO DO PROFESSOR (O Reset):
    // "após excluir o último elemento da Fila, faça com que a fila volte ao estado de fila vazia."
    // Isso evita o desperdício de memória caso a fila seja esvaziada.
    if (*inicio == *fim) {
        *inicio = 0;
        *fim = 0;
    }
}

int main() {
    int capacidade;
    
    // Lê o tamanho máximo da fila
    if (scanf("%d", &capacidade) != 1) return 0;
    
    // Alocação dinâmica da fila
    int *fila = (int *)malloc(capacidade * sizeof(int));
    
    // A Fila começa vazia, com início e fim no índice 0
    int inicio = 0;
    int fim = 0;
    
    char operacao;
    int valor;
    
    // Lê as operações até o End Of File (EOF)
    while (scanf(" %c", &operacao) != EOF) {
        if (operacao == 'E') {
            scanf("%d", &valor);
            enfileirar(fila, &fim, capacidade, valor);
        } else if (operacao == 'D') {
            desenfileirar(fila, &inicio, &fim);
        }
    }
    
    free(fila); // Libera a memória no final
    
    return 0;
}