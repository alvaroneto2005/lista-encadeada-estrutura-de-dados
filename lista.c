#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *prox;
};

typedef struct No No;

No* criaLista() {
    return NULL;
}

int listaVazia(No *lista) {
    return (lista == NULL);
}

int tamanho(No *lista) {
    int t = 0;
    No *atual = lista;
    while (atual != NULL) {
        t++;
        atual = atual->prox;
    }
    return t;
}

int obter(No *lista, int pos, int *v) {
    int tam = tamanho(lista);
    if (pos < 1 || pos > tam) return 0;

    No *atual = lista;
    for (int i = 1; i < pos; i++) {
        atual = atual->prox;
    }

    *v = atual->valor;
    return 1;
}

int modificar(No *lista, int pos, int valor) {
    int tam = tamanho(lista);
    if (pos < 1 || pos > tam) return 0;

    No *atual = lista;
    for (int i = 1; i < pos; i++) {
        atual = atual->prox;
    }

    atual->valor = valor;
    return 1;
}

int inserir(No **lista, int pos, int valor) {
    int tam = tamanho(*lista);
    if (pos < 1 || pos > tam + 1) return 0;

    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;

    if (pos == 1) {
        novo->prox = *lista;
        *lista = novo;
        return 1;
    }

    No *atual = *lista;
    for (int i = 1; i < pos - 1; i++) {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;

    return 1;
}

int remover(No **lista, int pos, int *v) {
    int tam = tamanho(*lista);
    if (pos < 1 || pos > tam) return 0;

    No *atual = *lista;

    if (pos == 1) {
        *v = atual->valor;
        *lista = atual->prox;
        free(atual);
        return 1;
    }

    No *anterior = NULL;
    for (int i = 1; i < pos; i++) {
        anterior = atual;
        atual = atual->prox;
    }

    *v = atual->valor;
    anterior->prox = atual->prox;
    free(atual);

    return 1;
}

void imprimir(No *lista) {
    No *atual = lista;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}
