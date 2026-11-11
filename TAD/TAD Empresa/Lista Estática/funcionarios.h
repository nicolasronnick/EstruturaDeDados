#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

//ESTRUTURA DOS FUNCIONARIOS
typedef struct funcionarios Funcionarios;

//PROCEDIMENTOS PARA LIMPAR E PAUSAR 
void limpar(void);
void pause_continue(void);

//FUNÇÕES DE VERIFICAÇÃO
int lst_vazia(void);
int lst_cheia(void);

//FUNÇÕES PARA A MANIPULAÇÃO DA LISTA
void lst_insere(void);
void lst_remove(void);
void lst_busca(void);
void lst_mostrar(void);
#endif