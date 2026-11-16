
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

        printf("\n===== MENU PILHA DINAMICA =====\n");
        printf("1 - Verificar se esta vazia\n");
        printf("2 - Empilhar (PUSH)\n");
        printf("3 - Desempilhar (POP)\n");
        printf("4 - Consultar topo\n");
        printf("5 - Alterar topo\n");
        printf("6 - Destruir pilha\n");
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

                printf("\nDigite o valor: ");
                scanf("%d", &valor);

                if (pilha_push(valor)) {
                    printf("\nElemento empilhado com sucesso!\n");
                } else {
                    printf("\nErro: nao foi possivel alocar memoria!\n");
                }

                break;

            case 3:

                if (pilha_pop(&valor)) {
                    printf("\nElemento desempilhado: %d\n", valor);
                } else {
                    printf("\nErro: pilha vazia!\n");
                }

                break;

            case 4:

                if (pilha_consultar(&valor)) {
                    printf("\nElemento do topo: %d\n", valor);
                } else {
                    printf("\nErro: pilha vazia!\n");
                }

                break;

            case 5:

                printf("\nDigite o novo valor: ");
                scanf("%d", &valor);

                if (pilha_alterar(valor)) {
                    printf("\nElemento do topo alterado!\n");
                } else {
                    printf("\nErro: pilha vazia!\n");
                }

                break;

            case 6:

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
