
#include <stdio.h>
#include "pilha.h"

#define MAX 5

// Estrutura interna da pilha
static int pilha[MAX];
static int topo = -1;

// 1. Criar pilha vazia
void pilha_criar() {
    topo = -1;
}

// 2. Verificar se a pilha está vazia
int pilha_vazia() {
    return topo == -1;
}

// 3. Verificar se a pilha está cheia
int pilha_cheia() {
    return topo == MAX - 1;
}

// 4. Inserir elemento no topo (PUSH)
int pilha_push(int valor) {

    if (pilha_cheia()) {
        return 0;
    }

    topo++;

    pilha[topo] = valor;

    return 1;
}

// 5. Remover elemento do topo (POP)
int pilha_pop(int *valor) {

    if (pilha_vazia()) {
        return 0;
    }

    *valor = pilha[topo];

    topo--;

    return 1;
}

// 6. Consultar elemento do topo
int pilha_consultar(int *valor) {

    if (pilha_vazia()) {
        return 0;
    }

    *valor = pilha[topo];

    return 1;
}

// 7. Alterar elemento do topo
int pilha_alterar(int novo_valor) {

    if (pilha_vazia()) {
        return 0;
    }

    pilha[topo] = novo_valor;

    return 1;
}

// 8. Destruir / reinicializar a pilha
void pilha_destruir() {
    topo = -1;
}
