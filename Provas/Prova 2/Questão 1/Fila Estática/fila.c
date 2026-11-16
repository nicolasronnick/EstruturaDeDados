
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define MAX 5

// Estrutura interna da fila (encapsulamento)
static int fila[MAX];
static int inicio = 0;
static int fim = 0;
static int quantidade = 0;

void limpar(void){
    system("cls");
}

void pause_menu(void){
    system("pause");
}

// 1. Criar uma fila vazia
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

// 6. Consultar o primeiro elemento
int fila_consultar(int *valor) {

    if (fila_vazia()) {
        return 0;
    }

    *valor = fila[inicio];

    return 1;
}

// 7. Alterar o primeiro elemento
int fila_alterar(int novo_valor) {

    if (fila_vazia()) {
        return 0;
    }

    fila[inicio] = novo_valor;

    return 1;
}

// 8. Destruir a fila
void fila_destruir() {

    inicio = 0;
    fim = 0;
    quantidade = 0;
}
