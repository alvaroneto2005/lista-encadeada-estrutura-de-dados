#include <stdio.h>
#include "lista.c"

int main() {

    No *lista = criaLista();
    int valor;

    printf("=== TESTE: Lista inicialmente vazia ===\n");
    printf("Lista vazia? %d (1 = sim)\n\n", listaVazia(lista));

    printf("=== Inserindo elementos ===\n");
    inserir(&lista, 1, 10);
    inserir(&lista, 2, 20);
    inserir(&lista, 3, 30);
    inserir(&lista, 2, 15);
    imprimir(lista);

    printf("\n=== Teste obter elemento ===\n");
    obter(lista, 3, &valor);
    printf("Valor na posicao 3: %d\n\n", valor);

    printf("=== Teste modificar elemento ===\n");
    modificar(lista, 3, 99);
    imprimir(lista);

    printf("\n=== Teste remover elemento ===\n");
    remover(&lista, 2, &valor);
    printf("Valor removido: %d\n", valor);
    imprimir(lista);

    printf("\n=== Teste tamanho ===\n");
    printf("Tamanho atual da lista: %d\n", tamanho(lista));

    return 0;
}
