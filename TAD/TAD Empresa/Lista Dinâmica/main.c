#include "funcionarios.h"
#include <stdio.h>

int main(){
    Funcionarios *lista = NULL; //declaro uma lista NULA\VAZIA
    int opcao; //para controle do usuário

    do{
        limpar();
        menu();
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                lista = inserir_lst(lista);
                pausa_continua();
                break;

            case 2:
                lista = delete_lst(lista);
                pausa_continua();
                break;

            case 3:
                buscar_lst(lista);
                pausa_continua();
                break;

            case 4:
                mostrar_lst(lista);
                pausa_continua();
                break;

            case 5:
                liberar_lst(lista);
                lista = NULL;
                pausa_continua();
                break;

            case 6:
                liberar_lst(lista);
                lista = NULL;
                printf("Programa encerrado!\n");
                pausa_continua();
                break;
            default:
                printf("Opcao Invalida!\n");
                pausa_continua();
        }
    }while(opcao != 6);
}