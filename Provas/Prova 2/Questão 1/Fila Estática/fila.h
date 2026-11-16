
#ifndef FILA_H
#define FILA_H

void limpar(void);
void pause_menu(void);

// Criar uma fila vazia
void fila_criar();

// Verificar se está vazia ou cheia
int fila_vazia();
int fila_cheia();

// Inserir elemento no final
int fila_enfileirar(int valor);

// Remover elemento do início
int fila_desenfileirar();

// Consultar o primeiro elemento
int fila_consultar();

// Alterar o primeiro elemento
int fila_alterar(int novo_valor);

// Destruir a fila
void fila_destruir();

#endif
