
#include <stdio.h>
#include "matriz.h"

int colunas, linhas, tam;

void dimensiona_Matriz(int i, int j){
    linhas = i;
    colunas = j;
    tam = i * j;
}

void zera_Matriz(int vet[]){
    int i;

    for(i = 0; i < tam; i++){
        vet[i] = 0;
    }
}

int indice(int i, int j){
    return (i - 1) * colunas + (j - 1);
}

void imprime_Matriz(int vet[], int l, int c){
    int i, j;

    for(i = 1; i <= l; i++){
        for(j = 1; j <= c; j++){
            printf("%d ", vet[indice(i,j)]);
        }
        printf("\n");
    }
}

void adiciona_Elemento(int vet[], int valor, int i, int j){
    int indc = indice(i,j);
    vet[indc] = valor;
}

int busca_Elemento(int vet[], int i, int j){
    int elemento = indice(i,j);
    return vet[elemento];
}
