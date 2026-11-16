
#ifndef FILA_H
#define FILA_H

void pause_menu(void);
void limpar(void);
// Criar fila vazia
void fila_criar();

// Verificar se está vazia
int fila_vazia();

// Inserir elemento no final
int fila_enfileirar(int valor);

// Remover elemento do início
int fila_desenfileirar(int *valor);

// Consultar primeiro elemento
int fila_consultar(int *valor);

// Alterar primeiro elemento
int fila_alterar(int novo_valor);

// Destruir fila
void fila_destruir();

#endif
