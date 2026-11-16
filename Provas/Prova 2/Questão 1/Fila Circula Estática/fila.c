
#include <stdio.h>
#include "fila.h"

#define MAX 5

// Estrutura interna da fila
static int fila[MAX];
static int inicio = 0;
static int fim = 0;
static int quantidade = 0;

// 1. Criar fila vazia
void fila_criar() {
    inicio = 0;
    fim = 0;
    quantidade = 0;
}

// 2. Verificar se a fila está vazia
int fila_vazia() {
    return quantidade == 0;
}

// 3. Verificar se a fila está cheia
int fila_cheia() {
    return quantidade == MAX;
}

// 4. Inserir elemento no final da fila
int fila_enfileirar(int valor) {

    if (fila_cheia()) {
        return 0;
    }

    fila[fim] = valor;

    fim = (fim + 1) % MAX;

    quantidade++;

    return 1;
}

// 5. Remover elemento do início da fila
int fila_desenfileirar(int *valor) {

    if (fila_vazia()) {
        return 0;
    }

    *valor = fila[inicio];

    inicio = (inicio + 1) % MAX;

    quantidade--;

    return 1;
}

// 6. Consultar primeiro elemento
int fila_consultar(int *valor) {

    if (fila_vazia()) {
        return 0;
    }

    *valor = fila[inicio];

    return 1;
}

// 7. Alterar primeiro elemento
int fila_alterar(int novo_valor) {

    if (fila_vazia()) {
        return 0;
    }

    fila[inicio] = novo_valor;

    return 1;
}

// 8. Destruir fila
void fila_destruir() {

    inicio = 0;
    fim = 0;
    quantidade = 0;
}
