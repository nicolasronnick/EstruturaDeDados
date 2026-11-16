
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void pause_menu(void){
    system("pause");
}

void limpar(void){
    system("cls");
}

// Estrutura do nó
typedef struct No {
    int valor;
    struct No *prox;
} No;

// Ponteiros da fila
static No *inicio = NULL;
static No *fim = NULL;

// 1. Criar fila vazia
void fila_criar() {
    inicio = NULL;
    fim = NULL;
}

// 2. Verificar se a fila está vazia
int fila_vazia() {
    return inicio == NULL;
}

// 3. Inserir elemento no final da fila
int fila_enfileirar(int valor) {

    No *novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->valor = valor;
    novo->prox = NULL;

    if (fila_vazia()) {
        inicio = novo;
    } else {
        fim->prox = novo;
    }

    fim = novo;

    return 1;
}

// 4. Remover elemento do início da fila
int fila_desenfileirar(int *valor) {

    if (fila_vazia()) {
        return 0;
    }

    No *aux = inicio;

    *valor = aux->valor;

    inicio = inicio->prox;

    if (inicio == NULL) {
        fim = NULL;
    }

    free(aux);

    return 1;
}

// 5. Consultar primeiro elemento
int fila_consultar(int *valor) {

    if (fila_vazia()) {
        return 0;
    }

    *valor = inicio->valor;

    return 1;
}

// 6. Alterar primeiro elemento
int fila_alterar(int novo_valor) {

    if (fila_vazia()) {
        return 0;
    }

    inicio->valor = novo_valor;

    return 1;
}

// 7. Destruir fila
void fila_destruir() {

    No *aux;

    while (inicio != NULL) {

        aux = inicio;

        inicio = inicio->prox;

        free(aux);
    }

    fim = NULL;
}
