
#include <stdio.h>
#include "fila.h"

int main() {

    int opcao;
    int valor;

    // Criar fila vazia
    fila_criar();

    do {

        limpar();

        printf("\n===== MENU FILA ESTATICA =====\n");
        printf("1 - Verificar se esta vazia\n");
        printf("2 - Verificar se esta cheia\n");
        printf("3 - Enfileirar\n");
        printf("4 - Desenfileirar\n");
        printf("5 - Consultar inicio\n");
        printf("6 - Alterar inicio\n");
        printf("7 - Destruir fila\n");
        printf("0 - Sair\n");

        printf("\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                if (fila_vazia()) {
                    printf("\nA fila esta vazia!\n");
                } else {
                    printf("\nA fila nao esta vazia!\n");
                }
                pause_menu();
                break;

            case 2:
                if (fila_cheia()) {
                    printf("\nA fila esta cheia!\n");
                } else {
                    printf("\nA fila nao esta cheia!\n");
                }
                pause_menu();
                break;

            case 3:
                printf("\nDigite o valor: ");
                scanf("%d", &valor);

                if (fila_enfileirar(valor)) {
                    printf("\nElemento inserido com sucesso!\n");
                } else {
                    printf("\nErro: fila cheia!\n");
                }
                pause_menu();
                break;

            case 4:
                if (fila_desenfileirar(&valor)) {
                    printf("\nElemento removido: %d\n", valor);
                } else {
                    printf("\nErro: fila vazia!\n");
                }
                pause_menu();
                break;

            case 5:
                if (fila_consultar(&valor)) {
                    printf("\nPrimeiro elemento: %d\n", valor);
                } else {
                    printf("\nErro: fila vazia!\n");
                }
                pause_menu();
                break;

            case 6:
                printf("\nDigite o novo valor: ");
                scanf("%d", &valor);

                if (fila_alterar(valor)) {
                    printf("\nPrimeiro elemento alterado!\n");
                } else {
                    printf("\nErro: fila vazia!\n");
                }
                pause_menu();
                break;

            case 7:
                fila_destruir();
                printf("\nFila destruida com sucesso!\n");
                pause_menu();
                break;

            case 0:
                fila_destruir();
                printf("\nPrograma encerrado!\n");
                pause_menu();
                break;

            default:
                printf("\nOpcao invalida!\n");
                pause_menu();
        }

    } while (opcao != 0);

    return 0;
}
