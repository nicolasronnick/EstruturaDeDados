
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Estrutura do nó
typedef struct No {
    int valor;
    struct No *prox;
} No;

// Ponteiro do topo da pilha
static No *topo = NULL;

// 1. Criar pilha vazia
void pilha_criar() {
    pilha_destruir();
}

// 2. Verificar se a pilha está vazia
int pilha_vazia() {
    return topo == NULL;
}

// 3. Inserir elemento no topo (PUSH)
int pilha_push(int valor) {

    No *novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->valor = valor;

    novo->prox = topo;

    topo = novo;

    return 1;
}

// 4. Remover elemento do topo (POP)
int pilha_pop(int *valor) {

    if (pilha_vazia()) {
        return 0;
    }

    No *aux = topo;

    *valor = aux->valor;

    topo = topo->prox;

    free(aux);

    return 1;
}

// 5. Consultar elemento do topo
int pilha_consultar(int *valor) {

    if (pilha_vazia()) {
        return 0;
    }

    *valor = topo->valor;

    return 1;
}

// 6. Alterar elemento do topo
int pilha_alterar(int novo_valor) {

    if (pilha_vazia()) {
        return 0;
    }

    topo->valor = novo_valor;

    return 1;
}

// 7. Destruir pilha
void pilha_destruir() {

    No *aux;

    while (topo != NULL) {

        aux = topo;

        topo = topo->prox;

        free(aux);
    }
}
