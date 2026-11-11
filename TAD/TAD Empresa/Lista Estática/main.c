#include <stdio.h>
#include "funcionarios.h"

int main(){
    int opcao; //variavel de controle do Menu
    
    do{
        limpar();
        printf("==========MENU DE SELECAO==========\n");
        printf("1 - Adicionar Funcionario\n");
        printf("2 - Remover Funcionario\n");
        printf("3 - Buscar Funcionario\n");
        printf("4 - Mostrar Funcionarios Cadastados\n");
        printf("5 - Sair\n");
        printf("Digite a opcao que deseja realizar: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                lst_insere();
                break;

            case 2:
                lst_remove();
                break;

            case 3:
                lst_busca();
                break;

            case 4:
                lst_mostrar();
                break;

            case 5:
                printf("----------PROGRAMA ENCERRADO----------\n");
                pause_continue();
                break;

            default:
            printf("Opcao Invalida!\n");
            pause_continue();

        }
    }while(opcao != 5);
}