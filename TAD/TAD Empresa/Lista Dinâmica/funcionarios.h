#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

//estrutura dos funcionarios com o nó
typedef struct Funcionarios Funcionarios; 

//Procedimentos para manipular o controle, menu e limpeza para o usuário
void limpar(void);
void pausa_continua(void);
void menu(void);

//Funções e Procedimentos para manipulação da lista de funcionários
Funcionarios *inserir_lst(Funcionarios *lst); //Função para adicionar Func. na lista
Funcionarios *delete_lst(Funcionarios *lst); //Função para remover Func. da lista
Funcionarios *busca_Mat(Funcionarios *lst, int matricula); //busca a matricula do Func. desejada e retorna seu endereço
void buscar_lst(Funcionarios *lst); //Procedimento para buscar Func. na lista
void mostrar_lst(Funcionarios *lst); //Procedimento para mostrar os Func. cadastrados
void liberar_lst(Funcionarios *lst); //procedimento para liberar a lista

#endif