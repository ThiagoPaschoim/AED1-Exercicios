#include <stdio.h>
#include <stdlib.h>

/* =================================================================================================
 * ENUNCIADO DO PROBLEMA: PILHA DE INTEIROS (PilhaInt)
 * =================================================================================================
 * Implemente uma estrutura de dados do tipo pilha estática que armazenará números inteiros.
 * * ENTRADA:
 * A primeira linha da entrada consiste de um número inteiro N, 0 < N <= 1000000,
 * representando o tamanho da lista de itens da pilha.
 * Em seguida haverá uma sucessão indefinida de linhas com os comandos:
 * E <valor> : Empilha o item na pilha.
 * D         : Desempilha um item da pilha.
 * T         : Exibe o item que está no topo da pilha e salta uma linha.
 * X         : Exibe cada item da pilha do topo para a base (separados por espaço).
 * B         : Exibe cada item da pilha da base para o topo (separados por espaço).
 * * * RESTRIÇÕES:
 * - Caso tente empilhar em uma pilha cheia, ignore a ação.
 * - Caso tente desempilhar de uma pilha vazia, ignore a ação.
 * * * SAÍDA:
 * Várias linhas de acordo com as impressões. Sempre após a impressão salte uma linha.
 * =================================================================================================
 */

/* =================================================================================================
 * GUIA DE ESTUDO: A ESTRUTURA PILHA E COMO ALTERÁ-LA NA PROVA
 * =================================================================================================
 * O que é a variável 'topo'?
 * Ela guarda a quantidade de elementos na pilha e, ao mesmo tempo, aponta para o 
 * PRÓXIMO ÍNDICE VAZIO do vetor.
 * Exemplo: Se topo == 0, a pilha está vazia. Se topo == 3, os índices ocupados são 0, 1 e 2.
 * * Como alterar na prova:
 * Se o professor pedir uma "Pilha de Strings" (PilhaString), basta mudar o tipo de dado
 * do vetor alocado e usar `strcpy` na hora de empilhar, assim como fizemos no BubbleString.
 */

// 1. EMPILHAR (PUSH)
void empilhar(int *pilha, int *topo, int capacidade, int valor) {
    // Se a pilha já estiver cheia (topo alcançou o limite), ignora o comando
    if (*topo >= capacidade) {
        return;
    }
    // Coloca o valor no índice 'topo' e DEPOIS incrementa o topo
    pilha[*topo] = valor;
    (*topo)++;
}

// 2. DESEMPILHAR (POP)
void desempilhar(int *topo) {
    // Se a pilha estiver vazia, ignora o comando
    if (*topo <= 0) {
        return;
    }
    // Para remover de uma pilha estática, basta diminuir o topo.
    // O valor antigo fica no vetor como "lixo de memória" e será sobrescrito no futuro.
    (*topo)--;
}

// 3. MOSTRAR O TOPO (TOP / PEEK)
void mostrar_topo(int *pilha, int topo) {
    if (topo > 0) {
        // O último elemento inserido está sempre no índice (topo - 1)
        printf("%d\n", pilha[topo - 1]);
    }
}

// 4. MOSTRAR DO TOPO PARA A BASE (X)
// Como o topo é o último a entrar, lemos o vetor de trás para frente.
void mostrar_topo_base(int *pilha, int topo) {
    if (topo > 0) {
        for (int i = topo - 1; i >= 0; i--) {
            if (i < topo - 1) printf(" "); // Espaço antes dos elementos, exceto do primeiro impresso
            printf("%d", pilha[i]);
        }
        printf("\n");
    }
}

// 5. MOSTRAR DA BASE PARA O TOPO (B)
// A base da pilha é sempre o índice 0. Lemos do início ao fim.
void mostrar_base_topo(int *pilha, int topo) {
    if (topo > 0) {
        for (int i = 0; i < topo; i++) {
            if (i > 0) printf(" "); // Espaço antes dos elementos, exceto do primeiro impresso
            printf("%d", pilha[i]);
        }
        printf("\n");
    }
}

int main() {
    int capacidade;
    
    // Lê a capacidade máxima da pilha
    if (scanf("%d", &capacidade) != 1) return 0;
    
    // Alocação dinâmica OBRIGATÓRIA (N = 1.000.000) para evitar Stack Overflow
    int *pilha = (int *)malloc(capacidade * sizeof(int));
    int topo = 0; // Inicia a pilha vazia
    
    char operacao;
    int valor;
    
    // Lê os comandos até o fim do arquivo (EOF)
    // O espaço antes do %c garante que "Enters" e espaços em branco sejam ignorados
    while (scanf(" %c", &operacao) != EOF) {
        if (operacao == 'E') {
            scanf("%d", &valor);
            empilhar(pilha, &topo, capacidade, valor);
            
        } else if (operacao == 'D') {
            desempilhar(&topo);
            
        } else if (operacao == 'T') {
            mostrar_topo(pilha, topo);
            
        } else if (operacao == 'X') {
            mostrar_topo_base(pilha, topo);
            
        } else if (operacao == 'B') {
            mostrar_base_topo(pilha, topo);
        }
    }
    
    free(pilha); // Boas práticas: sempre liberar a memória
    
    return 0;
}