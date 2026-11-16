
#include <stdio.h>
#include "matriz.h"

int main(){

    int linhas = 3;
    int colunas = 3;
    int tam = linhas * colunas;

    dimensiona_Matriz(linhas, colunas);

    int vet[tam];

    zera_Matriz(vet);

    imprime_Matriz(vet, linhas, colunas);

    printf("\n");

    adiciona_Elemento(vet, 15, 1, 1);
    adiciona_Elemento(vet, 25, 2, 2);
    adiciona_Elemento(vet, 35, 3, 3);

    imprime_Matriz(vet, linhas, colunas);

    printf("\n");

    printf("O elemento que esta na linha 2 e coluna 2 eh %d\n",
           busca_Elemento(vet, 2, 2));

    return 0;
}
