#include <stdio.h>

/* =================================================================================================
 * ENUNCIADO DO PROBLEMA: COPA DO MUNDO (CopaDoMundo)
 * =================================================================================================
 * Na Copa do Mundo, dezesseis equipes disputam a Fase Final, composta de 15 jogos eliminatórios.
 * As equipes são nomeadas de 'A' a 'P'.
 * * ENTRADA:
 * A entrada é composta de 15 linhas, cada uma contendo o resultado de um jogo.
 * O resultado de um jogo é representado por dois números inteiros M e N separados por espaço, 
 * indicando os gols da equipe à esquerda e à direita.
 * * * RESTRIÇÕES:
 * 0 <= M, N <= 20 e M != N (não há empates).
 * * * SAÍDA:
 * Uma única linha contendo a letra identificadora da equipe campeã, seguida de quebra de linha.
 * =================================================================================================
 */

/* =================================================================================================
 * GUIA DE ESTUDO: POR QUE A FILA RESOLVE O CHAVEAMENTO?
 * =================================================================================================
 * A Fila simula exatamente a progressão de fases (Oitavas -> Quartas -> Semi -> Final).
 * Imagine a Fila inicial: [A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P]
 * - Jogo 1: Tiramos A e B. A ganha. Fila vira: [C, D, E, F..., P, A]
 * - Jogo 2: Tiramos C e D. D ganha. Fila vira: [E, F, G, H..., P, A, D]
 * Perceba que, naturalmente, os vencedores das oitavas (A e D) estão se posicionando no
 * fim da fila para se enfrentarem mais tarde nas Quartas-de-final (Jogo 9)!
 * A estrutura FIFO organiza as rodadas automaticamente sem precisarmos de matrizes.
 * * * Como alterar na prova:
 * Se o professor pedir o VICE-CAMPEÃO: Basta alterar a lógica do Jogo 15 (o último do laço). 
 * No Jogo 15, o time que PERDER é o vice-campeão. Você faria um `if (i == 14) { imprimir perdedor }`.
 * =================================================================================================
 */

int main() {
    // Fila estática simples. 
    // Entram 16 times e depois mais 15 vencedores. Total de "empilhamentos" = 31.
    // Um vetor de 40 posições é perfeitamente seguro e previne Stack Overflow.
    char fila[40];
    int inicio = 0;
    int fim = 0;

    // 1. INICIALIZAÇÃO DA FILA (Oitavas de final)
    // Colocamos as 16 equipes ('A' até 'P') na fila inicial
    for (char equipe = 'A'; equipe <= 'P'; equipe++) {
        fila[fim] = equipe;
        fim++;
    }

    // 2. SIMULAÇÃO DOS JOGOS ELIMINATÓRIOS
    // A Fase Final tem exatamente 15 jogos
    for (int i = 0; i < 15; i++) {
        int gols_esq, gols_dir;
        
        // Lê os gols das duas equipes que vão se enfrentar
        if (scanf("%d %d", &gols_esq, &gols_dir) != 2) break;

        // "Desenfileira" as duas próximas equipes (as que vão jogar agora)
        char equipe_esq = fila[inicio++];
        char equipe_dir = fila[inicio++];

        // Quem fez mais gols é "Enfileirado" novamente no fim da fila para a próxima fase
        if (gols_esq > gols_dir) {
            fila[fim++] = equipe_esq;
        } else {
            fila[fim++] = equipe_dir;
        }
    }

    // 3. O CAMPEÃO
    // Após os 15 jogos, os 15 perdedores foram descartados.
    // O ponteiro 'inicio' estará apontando exatamente para o único time que sobrou.
    printf("%c\n", fila[inicio]);

    return 0;
}