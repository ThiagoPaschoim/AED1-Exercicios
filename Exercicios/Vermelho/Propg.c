/* =================================================================================================
 * GUIA DEFINITIVO DE REVISÃO DA PROVA 2: O BOSS FINAL (PROPG)
 * =================================================================================================
 * ENUNCIADO DO PROBLEMA: 187 - PROPG
 * O conselho universitário proibiu estruturas do tipo Pilha na graduação.
 * Sua missão é implementar um sistema de Pilha de Strings (com comandos de Empilhar, Desempilhar,
 * Topo, Imprimir Topo-Base e Imprimir Base-Topo) usando SOMENTE ESTRUTURAS DO TIPO FILA.
 * Você deve criar e usar as seguintes funções de Fila sem modificá-las:
 * enfileirar(), desenfileirar(), primeiro(), ultimo(), filaVazia(), mostrarFila(), 
 * criarFila() e criarItem().
 * * -------------------------------------------------------------------------------------------------
 * A LÓGICA DO "DUAL-QUEUE" (O SEGREDO PARA O 10):
 * Como simulamos uma Pilha (LIFO) usando uma Fila (FIFO)? 
 * Nós manteremos duas filas rodando em paralelo para os nossos dados:
 * * 1. Fila Base-Topo (F_BT): Funciona como uma fila normal. O primeiro inserido fica na frente.
 * - Quando o usuário chamar o comando 'B' (imprimir Base até Topo), apenas damos um 
 * mostrarFila(&F_BT) e o problema está resolvido de graça!
 * * 2. Fila Topo-Base (F_TB): Esta é a fila que sofre a "mágica" para agir como Pilha.
 * - INSERÇÃO (E): Para que o último elemento inserido fique na frente da Fila, nós criamos uma 
 * Fila Temporária (temp). Colocamos o NOVO elemento lá. Depois, esvaziamos toda a F_TB atrás 
 * desse novo elemento. O novo elemento torna-se o 'primeiro()'.
 * - REMOÇÃO (D): Como o topo está na frente da F_TB, um simples desenfileirar(&F_TB) remove 
 * o topo da pilha! Para manter a F_BT sincronizada, nós esvaziamos a F_BT numa Fila Temporária 
 * e descartamos apenas o último elemento desenfileirado.
 * * -------------------------------------------------------------------------------------------------
 * REGRAS DO BOCA PARA ESTE EXERCÍCIO:
 * - O comando D exibe a string removida entre colchetes: [string]
 * - O comando T exibe a string do topo entre parênteses: (string)
 * - Comandos devem ser ignorados se a pilha estiver vazia.
 * - As strings têm no máximo 50 caracteres (usaremos um array de 55 por segurança).
 * * =================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =================================================================================================
// 1. OBRIGAÇÃO DA PROVA: IMPLEMENTAÇÃO PADRÃO INTACTA DA FILA E DO ITEM
// =================================================================================================

// Estrutura do Item (conforme exigido pelo PDF)
typedef struct {
    char valor[55]; // Suporta até 50 caracteres + margem de segurança
} Item;

// Função criarItem
Item criarItem(char *str) {
    Item novo;
    strcpy(novo.valor, str);
    return novo;
}

// Estrutura do Nó da Fila
typedef struct No {
    Item item;
    struct No *prox;
} No;

// Estrutura da Fila
typedef struct {
    No *inicio;
    No *fim;
} Fila;

// Função criarFila
void criarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

// Função filaVazia
int filaVazia(Fila *f) {
    return (f->inicio == NULL);
}

// Função enfileirar (Insere sempre no fim)
void enfileirar(Fila *f, Item item) {
    No *novo = (No *)malloc(sizeof(No));
    novo->item = item;
    novo->prox = NULL;
    
    if (filaVazia(f)) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

// Função desenfileirar (Remove sempre do início)
Item desenfileirar(Fila *f) {
    No *temp = f->inicio;
    Item removido = temp->item;
    
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    free(temp); // Evita memory leak
    return removido;
}

// Função primeiro (Olha o início sem remover)
Item primeiro(Fila *f) {
    return f->inicio->item;
}

// Função ultimo (Olha o fim sem remover)
Item ultimo(Fila *f) {
    return f->fim->item;
}

// Função mostrarFila (Imprime do início ao fim, separados por espaço)
void mostrarFila(Fila *f) {
    if (filaVazia(f)) return;
    
    No *atual = f->inicio;
    int primeiro_espaco = 1;
    
    while (atual != NULL) {
        if (!primeiro_espaco) {
            printf(" ");
        }
        printf("%s", atual->item.valor);
        primeiro_espaco = 0;
        atual = atual->prox;
    }
    printf("\n"); // O exigido salto de linha no final
}

// =================================================================================================
// 2. O PROGRAMA PRINCIPAL (A SIMULAÇÃO DA PILHA USANDO AS FILAS)
// =================================================================================================

int main() {
    // Declaramos as nossas duas filas vitais
    Fila f_tb; // Topo para Base (Topo é o início da fila)
    Fila f_bt; // Base para Topo (Base é o início da fila)
    
    criarFila(&f_tb);
    criarFila(&f_bt);
    
    char operacao;
    char buffer[55];
    
    // O espaço no scanf(" %c") é crucial para evitar ler "enters" quebrados
    while (scanf(" %c", &operacao) != EOF) {
        
        // --- OPERAÇÃO DE EMPILHAR (E) ---
        if (operacao == 'E') {
            scanf("%s", buffer);
            Item novoItem = criarItem(buffer);
            
            // 1. Atualizamos a F_BT normalmente
            enfileirar(&f_bt, novoItem);
            
            // 2. Atualizamos a F_TB com a "Mágica" do empilhamento invertido
            Fila temp;
            criarFila(&temp);
            enfileirar(&temp, novoItem); // O novo item entra primeiro na temporária
            
            // Desenfileiramos todos os velhos e os colocamos atrás do novo
            while (!filaVazia(&f_tb)) {
                enfileirar(&temp, desenfileirar(&f_tb));
            }
            f_tb = temp; // A fila Topo-Base agora aponta para a nova organização
        } 
        
        // --- OPERAÇÃO DE DESEMPILHAR (D) ---
        else if (operacao == 'D') {
            // Regra: ignorar se estiver vazia
            if (filaVazia(&f_tb)) continue;
            
            // 1. Removemos da F_TB (O topo é sempre o primeiro, então é O(1))
            Item removido = desenfileirar(&f_tb);
            
            // 2. Removemos da F_BT (Como o topo está no final dela, é O(N))
            Fila temp;
            criarFila(&temp);
            while (!filaVazia(&f_bt)) {
                Item it = desenfileirar(&f_bt);
                // Se a fila ainda não esvaziou, não era o topo, então guardamos na temp
                if (!filaVazia(&f_bt)) {
                    enfileirar(&temp, it);
                }
                // O último elemento é simplesmente descartado!
            }
            f_bt = temp; // Atualizamos a F_BT
            
            // Imprime no formato exigido
            printf("[%s]\n", removido.valor);
        } 
        
        // --- OPERAÇÃO EXIBIR TOPO (T) ---
        else if (operacao == 'T') {
            // Regra: ignorar se estiver vazia
            if (filaVazia(&f_tb)) continue;
            
            // Como a F_TB mantém o topo na frente, basta olhar o 'primeiro'
            Item topo = primeiro(&f_tb);
            printf("(%s)\n", topo.valor);
        } 
        
        // --- OPERAÇÃO EXIBIR TOPO PARA A BASE (X) ---
        else if (operacao == 'X') {
            if (!filaVazia(&f_tb)) {
                mostrarFila(&f_tb);
            }
        } 
        
        // --- OPERAÇÃO EXIBIR BASE PARA O TOPO (B) ---
        else if (operacao == 'B') {
            if (!filaVazia(&f_bt)) {
                mostrarFila(&f_bt);
            }
        }
    }
    
    return 0;
}