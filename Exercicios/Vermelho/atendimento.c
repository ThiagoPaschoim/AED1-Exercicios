#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar os 4 dados requeridos, além do ID de entrada e a duração
typedef struct {
    int id;               // ID de chegada para critério de desempate
    char matricula[12];   // 11 caracteres + terminador nulo 
    char nome[105];       // Limite de 100 caracteres + segurança 
    int duracao_segundos; // Tempo total do atendimento
} Atendimento;

// Função de comparação para o qsort
int comparar(const void *a, const void *b) {
    Atendimento *atendimentoA = (Atendimento *)a;
    Atendimento *atendimentoB = (Atendimento *)b;

    // Critério 1: Maior tempo de atendimento primeiro (ordem decrescente) [cite: 53]
    if (atendimentoA->duracao_segundos != atendimentoB->duracao_segundos) {
        return atendimentoB->duracao_segundos - atendimentoA->duracao_segundos;
    }
    
    // Critério 2: Desempate pela ordem de registro na entrada (ordem crescente de ID) 
    return atendimentoA->id - atendimentoB->id;
}

int main() {
    int q;
    
    // Lê a quantidade de alunos (1 a 1000) [cite: 36, 43]
    if (scanf("%d", &q) != 1) return 0;
    
    // Aloca a lista dinamicamente
    Atendimento *lista = (Atendimento *)malloc(q * sizeof(Atendimento));
    if (lista == NULL) return 1;

    for (int i = 0; i < q; i++) {
        lista[i].id = i; // Registra a ordem original de chegada
        
        int h1, m1, s1;
        int h2, m2, s2;
        
        // Lê: Matrícula, Nome, H1 (Início) e H2 (Fim) [cite: 37, 38, 39, 40, 41]
        scanf("%s %s %d:%d:%d %d:%d:%d", 
              lista[i].matricula, 
              lista[i].nome, 
              &h1, &m1, &s1, 
              &h2, &m2, &s2);
              
        // Converte os horários para segundos
        int tempo_inicio = h1 * 3600 + m1 * 60 + s1;
        int tempo_fim = h2 * 3600 + m2 * 60 + s2;
        
        int duracao = tempo_fim - tempo_inicio;
        
        // Trata o caso onde o atendimento virou para o dia seguinte 
        if (duracao < 0) {
            duracao += 24 * 3600; // Adiciona as 24h em segundos
        }
        
        lista[i].duracao_segundos = duracao;
    }

    // Ordena a lista inteira baseada na função 'comparar'
    qsort(lista, q, sizeof(Atendimento), comparar);

    // Imprime o resultado formatado conforme exigido [cite: 54]
    for (int i = 0; i < q; i++) {
        printf("[%s] %s\n", lista[i].matricula, lista[i].nome);
    }

    free(lista);
    return 0;
}