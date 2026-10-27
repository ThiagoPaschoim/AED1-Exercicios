#include <stdio.h>
#include <stdlib.h>

/* =================================================================================================
 * ENUNCIADO DO PROBLEMA: FILA DINÂMICA (FilaDinamica)
 * =================================================================================================
 * Faça um programa que implemente uma Fila Dinâmica.
 * * ENTRADA:
 * Sucessão indefinida de comandos:
 * E <valor> : Inclusão do Valor na Fila (no fim)
 * D         : Exclusão do Valor na Fila (do início)
 * M         : Exibir os valores da Fila
 * * * RESTRIÇÕES:
 * - VALOR será um natural entre 0 e 100000.
 * - Caso tente excluir de uma Fila Vazia, a operação deve ser ignorada.
 * * * SAÍDA:
 * - Na exclusão (D), exibir o valor removido entre sinais de menor/maior, ex: <10>.
 * - Na exibição (M), elementos separados por espaço com quebra de linha ao final.
 * =================================================================================================
 */

/* =================================================================================================
 * GUIA DE ESTUDO: O GERENCIADOR DA FILA
 * =================================================================================================
 * Diferente da LDE básica, aqui agrupamos os ponteiros 'inicio' e 'fim' dentro 
 * de uma struct chamada 'Fila'.
 * - 'inicio' é usado na hora de REMOVER (D).
 * - 'fim' é usado na hora de INSERIR (E), o que garante que a inserção seja
 * instantânea, não importando se a fila tem 10 ou 1 milhão de elementos.
 */

// A planta baixa de cada elo da corrente
typedef struct No {
    int valor;
    struct No *prox;
} No;

// O controle (gerenciador) da nossa Fila
typedef struct {
    No *inicio;
    No *fim;
} Fila;

// 1. INSERIR (ENQUEUE) - Ocorre SEMPRE no 'fim'
void inserir(Fila *f, int valor) {
    // 1º Passo: Fabricar o novo nó
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL; // Como ele entrará no final, não tem ninguém depois dele

    // 2º Passo: Ligar o nó na fila
    if (f->fim == NULL) {
        // Se o fim é nulo, a fila estava VAZIA. O novo nó é o início e o fim ao mesmo tempo.
        f->inicio = novo;
        f->fim = novo;
    } else {
        // A fila já tem gente. O último nó atual estende o braço (prox) para segurar o novo nó
        f->fim->prox = novo;
        // O gerenciador atualiza sua prancheta: o 'fim' oficial agora é este novo nó
        f->fim = novo;
    }
}

// 2. REMOVER (DEQUEUE) - Ocorre SEMPRE no 'inicio'
void remover(Fila *f) {
    // Regra do PDF: Ignorar se estiver vazia
    if (f->inicio == NULL) {
        return;
    }

    // Guarda quem está no início atualmente para não perdermos o endereço
    No *temp = f->inicio;
    int valor_removido = temp->valor;

    // O início da fila pula para o 2º da fila (que pode ser NULL se só tinha 1 pessoa)
    f->inicio = f->inicio->prox;

    // Se o início ficou NULL, significa que a fila esvaziou. 
    // Logo, o 'fim' também não pode apontar para o vazio (lixo).
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    // Libera a memória da pessoa que foi atendida e saiu
    free(temp);

    // O detalhe crucial do BOCA: imprimir entre < e >
    printf("<%d>\n", valor_removido);
}

// 3. MOSTRAR (EXIBIR FILA)
void mostrar(Fila *f) {
    // Se a fila estiver vazia, não imprime nada e sai
    if (f->inicio == NULL) return;

    No *atual = f->inicio;
    int primeiro = 1;

    // Caminha pela fila até encontrar o fim (NULL)
    while (atual != NULL) {
        if (!primeiro) {
            printf(" ");
        }
        printf("%d", atual->valor);
        primeiro = 0;
        
        atual = atual->prox; // Pula para o próximo
    }
    printf("\n"); // Exigência do BOCA
}

int main() {
    Fila f;
    // Inicializa a fila corretamente como vazia
    f.inicio = NULL;
    f.fim = NULL;

    char operacao;
    int valor;

    // Lê até o EOF
    while (scanf(" %c", &operacao) != EOF) {
        if (operacao == 'E') {
            scanf("%d", &valor);
            inserir(&f, valor);
            
        } else if (operacao == 'D') {
            remover(&f);
            
        } else if (operacao == 'M') {
            mostrar(&f);
        }
    }

    // Boas práticas: se o programa terminar e a fila não estiver vazia, liberar a memória restante
    while (f.inicio != NULL) {
        No *temp = f.inicio;
        f.inicio = f.inicio->prox;
        free(temp);
    }

    return 0;
}