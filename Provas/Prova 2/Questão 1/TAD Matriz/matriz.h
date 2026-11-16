#ifndef MATRIZ_H
#define MATRIZ_H

void dimensiona_Matriz(int i, int j);
void zera_Matriz(int vet[]);
int indice(int i, int j);
void imprime_Matriz(int vet[], int l ,int c);
void adiciona_Elemento(int vet[], int valor, int i, int j);
int busca_Elemento(int vet[], int i, int j);

#endif