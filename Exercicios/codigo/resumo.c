// =================================================================================================
// ARQUIVO 1: simulado_batata_quente.c (O "Boss" de Fila Dinâmica)
// =================================================================================================
/*
 * ENUNCIADO: "A Apresentação de Projetos (Batata Quente)"
 * O professor de Algoritmos decidiu que a ordem de apresentação dos projetos finais será decidida
 * por um jogo. Os N alunos formam uma roda. O professor escolhe um número inteiro K. 
 * A partir do primeiro aluno, conta-se K posições na roda. O aluno que estiver na K-ésima posição 
 * sai da roda e vai apresentar o projeto. A contagem recomeça a partir do PRÓXIMO aluno na roda, 
 * até que todos tenham apresentado.
 * * ENTRADA:
 * A primeira linha contém dois inteiros N (número de alunos) e K (o salto), onde 0 < N, K <= 100000.
 * A segunda linha contém os nomes dos N alunos (strings sem espaço, máx 30 caracteres).
 * * SAÍDA:
 * Uma única linha com os nomes dos alunos na ordem em que vão apresentar, separados por espaço,
 * com uma quebra de linha no final.
 * * -------------------------------------------------------------------------------------------------
 * POR QUE ISSO CAI NA PROVA? 
 * Este é o clássico Problema de Josephus. A forma mais fácil e eficiente de resolver é usando 
 * uma Fila (FIFO). A lógica é genial: 
 * Para simular a "roda", você desenfileira um aluno e enfileira ele mesmo no final da fila (ele 
 * vai pro fim da roda). Faça isso K-1 vezes. O aluno que estiver na frente agora é o K-ésimo! 
 * Você o desenfileira de vez e imprime o nome dele.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do Nó da Fila Dinâmica de Strings
typedef struct NoFila {
    char nome[35];
    struct NoFila *prox;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
} FilaCircularSimulada;

// Funções padrão de Fila Dinâmica
void enfileirar(FilaCircularSimulada *f, char *nome) {
    NoFila *novo = (NoFila *)malloc(sizeof(NoFila));
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    if (f->fim == NULL) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
}

// Retorna 1 se estiver vazia, 0 caso contrário
int vazia(FilaCircularSimulada *f) {
    return (f->inicio == NULL);
}

// Remove do início e copia o nome removido para a variável de destino
void desenfileirar(FilaCircularSimulada *f, char *destino) {
    if (vazia(f)) return;
    NoFila *temp = f->inicio;
    strcpy(destino, temp->nome);
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) f->fim = NULL;
    free(temp);
}

int main_simulado_1() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    FilaCircularSimulada roda;
    roda.inicio = NULL;
    roda.fim = NULL;

    char nome[35];
    // Enfileira todos os alunos na ordem inicial
    for (int i = 0; i < n; i++) {
        scanf("%s", nome);
        enfileirar(&roda, nome);
    }

    int primeiro_impresso = 1;

    // Enquanto houver alunos na roda
    while (!vazia(&roda)) {
        // Pula K-1 alunos (tira da frente e joga pro final)
        for (int i = 0; i < k - 1; i++) {
            desenfileirar(&roda, nome);
            enfileirar(&roda, nome);
        }
        
        // O K-ésimo aluno é removido definitivamente e apresenta
        desenfileirar(&roda, nome);
        
        // Formatação BOCA: espaços entre as palavras, sem espaço no fim
        if (!primeiro_impresso) printf(" ");
        printf("%s", nome);
        primeiro_impresso = 0;
    }
    printf("\n");

    return 0;
}


// =================================================================================================
// ARQUIVO 2: simulado_intersecao_ldde.c (A Variação Mais Provável do DiferencaLDDE)
// =================================================================================================
/*
 * ENUNCIADO: "Interseção de Listas Duplamente Encadeadas"
 * O professor pediu a Diferença (A - B) na sua lista de exercícios. Na prova, ele pode muito 
 * bem pedir a INTERSEÇÃO (A ∩ B) ou a UNIÃO (A ∪ B). 
 * Faça uma função `struct tLista * intersectLists(struct tLista *A, struct tLista *B)` que 
 * retorna uma nova LDDE apenas com os elementos que estão presentes em AMBAS as listas.
 * * -------------------------------------------------------------------------------------------------
 * COMO ADAPTAR NA HORA DA PROVA:
 * - Para INTERSEÇÃO: Se A == B, insere e avança os dois. Se A < B, avança A. Se B < A, avança B.
 * - Para UNIÃO: Se A == B, insere um deles e avança OS DOIS. Se A < B, insere A e avança A. 
 * Se B < A, insere B e avança B. Depois não esqueça de fazer um while para inserir o que 
 * sobrar de A e de B (como no MergeSort).
 */

#include <stdio.h>
#include <stdlib.h>

struct tNo {
    int valor;
    struct tNo *prox;
    struct tNo *ant;
};

struct tLista {
    struct tNo *inicio;
    struct tNo *fim;
};

// ... (Suponha que as funções criarLista, inserir_ordenado e exibir estejam aqui, 
// iguais às do DiferencaLDDE que fizemos anteriormente).

struct tLista * intersectLists(struct tLista *A, struct tLista *B) {
    struct tLista *res = (struct tLista *)malloc(sizeof(struct tLista));
    res->inicio = NULL; res->fim = NULL; // criarLista

    struct tNo *pA = A->inicio;
    struct tNo *pB = B->inicio;

    // A mágica O(N) da Interseção
    while (pA != NULL && pB != NULL) {
        if (pA->valor == pB->valor) {
            // Achou um elemento comum! Insere na lista resultante
            // (Chame a função de inserção normal da LDDE aqui)
            // inserir(res, pA->valor);
            
            // Avança ambos os ponteiros
            pA = pA->prox;
            pB = pB->prox;
        } 
        else if (pA->valor < pB->valor) {
            // Se A é menor, esse valor de A não tem como estar em B, pois B já é maior.
            // Avança apenas o A para tentar alcançar o B.
            pA = pA->prox;
        } 
        else { // pB->valor < pA->valor
            // Se B é menor, avança o B.
            pB = pB->prox;
        }
    }

    return res;
}


// =================================================================================================
// ARQUIVO 3: simulado_pilha_rastreada.c (A Prova de Implementação de Pilha)
// =================================================================================================
/*
 * ENUNCIADO: "Rastreio de Estado da Pilha Dinâmica"
 * Para provar que você não usou bibliotecas prontas, implemente uma Pilha Dinâmica.
 * O programa receberá comandos 'I <valor>' (Empilhar) e 'R' (Desempilhar).
 * *Regra de Ouro*: APÓS CADA OPERAÇÃO BEM SUCEDIDA, você deve imprimir o estado completo 
 * da pilha (do topo para a base). Se a pilha ficar vazia (ou já estiver), imprima "VAZIA".
 * Operações inválidas (ex: remover de pilha vazia) devem ser ignoradas e NÃO devem acionar 
 * a impressão.
 * * -------------------------------------------------------------------------------------------------
 * POR QUE ISSO CAI NA PROVA?
 * É o equivalente exato aos exercícios "InsertionCorretude" e "OrdenaBubble" da Prova 1.
 * Ele quer ver os "estados intermediários". A Pilha Dinâmica insere e remove SEMPRE do 'topo'.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct NoPilha {
    int valor;
    struct NoPilha *prox; // O próximo aponta para o elemento de "baixo" na pilha
} NoPilha;

// Imprime do topo para a base (já que a LDE normal percorre do início(topo) ao fim(base))
void mostrar_rastreio(NoPilha *topo) {
    if (topo == NULL) {
        printf("VAZIA\n");
        return;
    }
    NoPilha *atual = topo;
    int primeiro = 1;
    while (atual != NULL) {
        if (!primeiro) printf(" ");
        printf("%d", atual->valor);
        primeiro = 0;
        atual = atual->prox;
    }
    printf("\n");
}

int main_simulado_3() {
    NoPilha *topo = NULL;
    char op;
    int valor;

    while (scanf(" %c", &op) != EOF) {
        if (op == 'I') {
            scanf("%d", &valor);
            
            // Lógica PUSH Dinâmico
            NoPilha *novo = (NoPilha *)malloc(sizeof(NoPilha));
            novo->valor = valor;
            novo->prox = topo; // Novo nó fica "em cima" do antigo topo
            topo = novo;       // Atualiza quem é o topo oficial
            
            // Imprime o estado após sucesso
            mostrar_rastreio(topo);
        } 
        else if (op == 'R') {
            // Ignora remoção se vazia (não imprime nada)
            if (topo == NULL) continue;
            
            // Lógica POP Dinâmico
            NoPilha *temp = topo;
            topo = topo->prox; // O topo desce um nível
            free(temp);        // Libera a memória do antigo topo
            
            // Imprime o estado após sucesso
            mostrar_rastreio(topo);
        }
    }
    return 0;
}


// =================================================================================================
// ARQUIVO 4: simulado_revolta_das_filas.c (O Boss Reverso do PROPG)
// =================================================================================================
/*
 * ENUNCIADO: "A Revolta das Filas (Fila usando Pilhas)"
 * Os alunos se revoltaram com o PROPG e baniram as Filas!
 * Sua missão é implementar um sistema de Fila (FIFO) usando SOMENTE operações de Pilha (LIFO).
 * Implemente comandos: E <valor> (Enfileirar), D (Desenfileirar e Imprimir).
 * * -------------------------------------------------------------------------------------------------
 * A LÓGICA (Tão genial quanto o PROPG):
 * Usamos DUAS Pilhas: Pilha_Entrada e Pilha_Saida.
 * - ENFILEIRAR (E): Simplesmente dê PUSH na Pilha_Entrada. O(1).
 * - DESENFILEIRAR (D): Como a Pilha_Entrada inverte a ordem (o mais velho fica no fundo), 
 * nós precisamos "virar o copo". Se a Pilha_Saida estiver vazia, damos POP em todos da 
 * Pilha_Entrada e damos PUSH na Pilha_Saida. Isso inverte tudo! O mais velho vai parar no 
 * topo da Pilha_Saida! Então é só dar POP na Pilha_Saida.
 */

#include <stdio.h>
#include <stdlib.h>

// Estrutura padrão de Pilha Dinâmica
typedef struct NoP {
    int valor;
    struct NoP *prox;
} NoP;

void push(NoP **topo, int valor) {
    NoP *novo = (NoP *)malloc(sizeof(NoP));
    novo->valor = valor;
    novo->prox = *topo;
    *topo = novo;
}

int pop(NoP **topo) {
    if (*topo == NULL) return -1;
    NoP *temp = *topo;
    int val = temp->valor;
    *topo = (*topo)->prox;
    free(temp);
    return val;
}

int pilha_vazia(NoP *topo) {
    return topo == NULL;
}

int main_simulado_4() {
    NoP *pilha_entrada = NULL;
    NoP *pilha_saida = NULL;
    
    char op;
    int valor;

    while (scanf(" %c", &op) != EOF) {
        if (op == 'E') {
            scanf("%d", &valor);
            // Enfileirar é apenas dar push na entrada
            push(&pilha_entrada, valor);
        } 
        else if (op == 'D') {
            // Se ambas estão vazias, a Fila está vazia. Ignora.
            if (pilha_vazia(pilha_entrada) && pilha_vazia(pilha_saida)) continue;
            
            // Se a saída estiver vazia, transferimos TUDO da entrada para a saída
            // Isso inverte a ordem, colocando o elemento mais antigo no TOPO da saída
            if (pilha_vazia(pilha_saida)) {
                while (!pilha_vazia(pilha_entrada)) {
                    int val = pop(&pilha_entrada);
                    push(&pilha_saida, val);
                }
            }
            
            // Removemos do topo da saída (que agora é o "início" da Fila)
            int removido = pop(&pilha_saida);
            printf("<%d>\n", removido);
        }
    }
    return 0;
}