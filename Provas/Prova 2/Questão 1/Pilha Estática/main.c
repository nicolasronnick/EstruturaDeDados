
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Limpar terminal
void limpar(void) {
    system("cls");
}

// Pausar menu
void pause_menu(void) {
    system("pause");
}

int main() {

    int opcao;
    int valor;

    // Criar pilha vazia
    pilha_criar();

    do {

        limpar();

        printf("\n===== MENU PILHA ESTATICA =====\n");
        printf("1 - Verificar se esta vazia\n");
        printf("2 - Verificar se esta cheia\n");
        printf("3 - Empilhar (PUSH)\n");
        printf("4 - Desempilhar (POP)\n");
        printf("5 - Consultar topo\n");
        printf("6 - Alterar topo\n");
        printf("7 - Destruir pilha\n");
        printf("0 - Sair\n");

        printf("\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:

                if (pilha_vazia()) {
                    printf("\nA pilha esta vazia!\n");
                } else {
                    printf("\nA pilha nao esta vazia!\n");
                }

                break;

            case 2:

                if (pilha_cheia()) {
                    printf("\nA pilha esta cheia!\n");
                } else {
                    printf("\nA pilha nao esta cheia!\n");
                }

                break;

            case 3:

                printf("\nDigite o valor: ");
                scanf("%d", &valor);

                if (pilha_push(valor)) {
                    printf("\nElemento empilhado com sucesso!\n");
                } else {
                    printf("\nErro: pilha cheia!\n");
                }

                break;

            case 4:

                if (pilha_pop(&valor)) {
                    printf("\nElemento desempilhado: %d\n", valor);
                } else {
                    printf("\nErro: pilha vazia!\n");
                }

                break;

            case 5:

                if (pilha_consultar(&valor)) {
                    printf("\nElemento do topo: %d\n", valor);
                } else {
                    printf("\nErro: pilha vazia!\n");
                }

                break;

            case 6:

                printf("\nDigite o novo valor: ");
                scanf("%d", &valor);

                if (pilha_alterar(valor)) {
                    printf("\nElemento do topo alterado!\n");
                } else {
                    printf("\nErro: pilha vazia!\n");
                }

                break;

            case 7:

                pilha_destruir();

                printf("\nPilha destruida com sucesso!\n");

                break;

            case 0:

                pilha_destruir();

                printf("\nPrograma encerrado!\n");

                break;

            default:

                printf("\nOpcao invalida!\n");
        }

        if (opcao != 0) {
            pause_menu();
        }

    } while (opcao != 0);

    return 0;
}
