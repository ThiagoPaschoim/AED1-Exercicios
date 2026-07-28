#include <stdio.h>
#include <stdlib.h>

/* =================================================================================================
 * ENUNCIADO DO PROBLEMA: LISTA DINÂMICA DUPLAMENTE ENCADEADA (LDDE)
 * =================================================================================================
 * Faça um programa que implemente uma Lista Dinâmica Duplamente Encadeada.
 * * ENTRADA:
 * Várias linhas no formato:
 * I <valor> : Inclusão do Valor na Lista (ordenado, sem repetição)
 * E <valor> : Exclusão do Valor na Lista
 * M         : Mostra a lista do início para o final
 * R         : Mostra a lista do final para o início
 * * * RESTRIÇÕES E SAÍDA:
 * - Ignorar operações inválidas (inserir repetido, remover o que não existe).
 * - Os comandos M e R exibem um valor após o outro separados por espaço.
 * - HÁ UM ESPAÇO EM BRANCO APÓS O ÚLTIMO VALOR EXIBIDO.
 * - Após exibir, pule uma linha (mesmo que a lista esteja vazia).
 * =================================================================================================
 */

/* =================================================================================================
 * GUIA DE ESTUDO: OS PONTEIROS 'PROX' E 'ANT'
 * =================================================================================================
 * Numa LDE simples, para remover um nó, precisávamos de um ponteiro 'atual' e de um 'anterior'
 * correndo atrás dele. Na LDDE não precisamos disso!
 * Como cada nó sabe quem está atrás dele (atraves do ponteiro 'ant'), basta encontrar o nó 
 * e usar o seu próprio 'ant' para fazer a costura.
 * * Usamos a struct LDDE (como fizemos na FilaDinamica) para guardar o 'inicio' e o 'fim'.
 * Isso torna o comando 'R' muito rápido, pois já sabemos onde a lista termina.
 */

// A planta baixa do Nó da LDDE
typedef struct No {
    int valor;
    struct No *prox;
    struct No *ant;   // A grande novidade: ponteiro para o nó de trás
} No;

// O Gerenciador da Lista
typedef struct {
    No *inicio;
    No *fim;
} LDDE;

// 1. INSERÇÃO ORDENADA E SEM REPETIÇÃO
void inserir(LDDE *lista, int valor) {
    No *atual = lista->inicio;

    // Caminha para a frente até achar o final ou alguém maior/igual
    while (atual != NULL && atual->valor < valor) {
        atual = atual->prox;
    }

    // Regra: Ignora se já existir
    if (atual != NULL && atual->valor == valor) {
        return; 
    }

    // Cria o novo nó
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    // CASO 1: A lista está totalmente vazia
    if (lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
        return;
    }

    // CASO 2: Inserção no Início (antes do primeiro elemento)
    if (atual == lista->inicio) {
        novo->prox = lista->inicio; // O novo aponta para a antiga cabeça
        lista->inicio->ant = novo;  // A antiga cabeça olha para trás e vê o novo
        lista->inicio = novo;       // Atualiza quem é a cabeça oficial
        return;
    }

    // CASO 3: Inserção no Fim (atual é NULL, passou de todo mundo)
    if (atual == NULL) {
        novo->ant = lista->fim;     // O novo olha para trás e vê o antigo fim
        lista->fim->prox = novo;    // O antigo fim estende o braço e segura o novo
        lista->fim = novo;          // Atualiza quem é o fim oficial
        return;
    }

    // CASO 4: Inserção no Meio (antes do 'atual')
    // A mágica acontece em 4 movimentos de costura:
    novo->prox = atual;             // 1. Novo aponta para o atual
    novo->ant = atual->ant;         // 2. Novo aponta para trás (para o vizinho do atual)
    atual->ant->prox = novo;        // 3. O vizinho de trás passa a apontar para o novo
    atual->ant = novo;              // 4. O atual passa a olhar para trás e ver o novo
}

// 2. EXCLUSÃO
void excluir(LDDE *lista, int valor) {
    No *atual = lista->inicio;

    // Busca o elemento
    while (atual != NULL && atual->valor < valor) {
        atual = atual->prox;
    }

    // Regra: Se não achou, ignora
    if (atual == NULL || atual->valor != valor) {
        return; 
    }

    // CASO 1: É o único elemento da lista
    if (atual == lista->inicio && atual == lista->fim) {
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    // CASO 2: Removendo o primeiro elemento
    else if (atual == lista->inicio) {
        lista->inicio = atual->prox;   // A cabeça passa para o segundo
        lista->inicio->ant = NULL;     // O novo primeiro nó não tem ninguém atrás
    }
    // CASO 3: Removendo o último elemento
    else if (atual == lista->fim) {
        lista->fim = atual->ant;       // O fim retrocede uma casa
        lista->fim->prox = NULL;       // O novo fim não tem ninguém à frente
    }
    // CASO 4: Removendo do meio
    else {
        // O nó de trás aponta para o da frente (pulando o atual)
        atual->ant->prox = atual->prox;
        // O nó da frente olha para trás e vê o de trás (pulando o atual)
        atual->prox->ant = atual->ant;
    }

    free(atual); // Libera o coitado do nó
}

// 3. MOSTRAR DO INÍCIO PARA O FIM (M)
void mostrar_M(LDDE *lista) {
    No *atual = lista->inicio;
    
    // A exigência bizarra do BOCA: imprime o número seguido de espaço SEMPRE.
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    // Salta a linha mesmo que não tenha imprimido nada
    printf("\n");
}

// 4. MOSTRAR DO FIM PARA O INÍCIO (R)
void mostrar_R(LDDE *lista) {
    No *atual = lista->fim;
    
    // Percorre usando o ponteiro 'ant'
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->ant;
    }
    // Salta a linha mesmo que não tenha imprimido nada
    printf("\n");
}

int main() {
    LDDE lista;
    lista.inicio = NULL;
    lista.fim = NULL;
    
    char operacao;
    int valor;

    // Lê os comandos até acabar
    while (scanf(" %c", &operacao) != EOF) {
        if (operacao == 'I') {
            scanf("%d", &valor);
            inserir(&lista, valor);
            
        } else if (operacao == 'E') {
            scanf("%d", &valor);
            excluir(&lista, valor);
            
        } else if (operacao == 'M') {
            mostrar_M(&lista);
            
        } else if (operacao == 'R') {
            mostrar_R(&lista);
        }
    }

    return 0;
}