
#ifndef PILHA_H
#define PILHA_H

// Criar pilha vazia
void pilha_criar();

// Verificar se está vazia ou cheia
int pilha_vazia();
int pilha_cheia();

// Inserir elemento no topo
int pilha_push(int valor);

// Remover elemento do topo
int pilha_pop(int *valor);

// Consultar elemento do topo
int pilha_consultar(int *valor);

// Alterar elemento do topo
int pilha_alterar(int novo_valor);

// Destruir pilha
void pilha_destruir();

#endif
