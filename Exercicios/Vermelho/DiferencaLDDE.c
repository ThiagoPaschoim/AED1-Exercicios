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

void criarLista(struct tLista *l) {
    l->inicio = NULL;
    l->fim = NULL;
}

void inserir(struct tLista *lista, int valor) {
    struct tNo *atual = lista->inicio;
    while (atual != NULL && atual->valor < valor) atual = atual->prox;
    if (atual != NULL && atual->valor == valor) return;

    struct tNo *novo = (struct tNo *)malloc(sizeof(struct tNo));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
    } else if (atual == lista->inicio) {
        novo->prox = lista->inicio;
        lista->inicio->ant = novo;
        lista->inicio = novo;
    } else if (atual == NULL) {
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
    } else {
        novo->prox = atual;
        novo->ant = atual->ant;
        atual->ant->prox = novo;
        atual->ant = novo;
    }
}

void excluir(struct tLista *lista, int valor) {
    struct tNo *atual = lista->inicio;
    while (atual != NULL && atual->valor < valor) atual = atual->prox;
    if (atual == NULL || atual->valor != valor) return;

    if (atual == lista->inicio && atual == lista->fim) {
        lista->inicio = NULL;
        lista->fim = NULL;
    } else if (atual == lista->inicio) {
        lista->inicio = atual->prox;
        lista->inicio->ant = NULL;
    } else if (atual == lista->fim) {
        lista->fim = atual->ant;
        lista->fim->prox = NULL;
    } else {
        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;
    }
    free(atual);
}

struct tLista * diffLists(struct tLista *A, struct tLista *B) {
    struct tLista *res = (struct tLista *)malloc(sizeof(struct tLista));
    criarLista(res);

    struct tNo *pA = A->inicio;
    struct tNo *pB = B->inicio;

    while (pA != NULL) {
        while (pB != NULL && pB->valor < pA->valor) pB = pB->prox;
        
        if (pB != NULL && pB->valor == pA->valor) {
            pA = pA->prox;
        } else {
            inserir(res, pA->valor);
            pA = pA->prox;
        }
    }
    return res;
}

void mostrar_M(struct tLista *lista) {
    struct tNo *atual = lista->inicio;
    while (atual != NULL) {
        // CORREÇÃO: Imprime o espaço no final (padrão que ele usou no exercício LDDE anterior)
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

void mostrar_R(struct tLista *lista) {
    struct tNo *atual = lista->fim;
    while (atual != NULL) {
        // CORREÇÃO: Imprime o espaço no final
        printf("%d ", atual->valor);
        atual = atual->ant;
    }
    printf("\n");
}

int main() {
    struct tLista ListaA, ListaB;
    criarLista(&ListaA);
    criarLista(&ListaB);

    char op, lst;
    int valor;

    while (scanf(" %c %c %d", &op, &lst, &valor) != EOF) {
        struct tLista *alvo = (lst == 'A') ? &ListaA : &ListaB;
        if (op == 'I') inserir(alvo, valor);
        else if (op == 'E') excluir(alvo, valor);
    }

    struct tLista *DAB = diffLists(&ListaA, &ListaB);
    struct tLista *DBA = diffLists(&ListaB, &ListaA);

    mostrar_M(DAB);
    mostrar_R(DAB);
    mostrar_M(DBA);
    mostrar_R(DBA);

    return 0;
}