#include "funcionarios.h"
#include <stdio.h>
#include <stdlib.h>

//campos de acesso para funcionários da lista
struct Funcionarios{
    char nome[100];
    int matricula;
    int idade;
    float salario;
    struct Funcionarios *prox;  //aponta para o próximo nó
};

//limpa coisas digitadas anteriormente
void limpar(void){
    system("cls");
}

//pede um digito para prosseguir
void pausa_continua(void){
    system("pause");
}

void menu(void){
    printf("=====MENU DE SELECAO=====\n");
    printf("1 - Adicionar Funcionario\n");
    printf("2 - Remover Funcionarios\n");   
    printf("3 - Buscar Funcionario\n");
    printf("4 - Mostrar Funcionarios Cadastrados\n");
    printf("5 - Liberar Lista\n");
    printf("6 - Sair\n");
    printf("Digite a opcao que deseja realizar: ");
}

//Função para verificar se existe matrícula, se existir, retorna o endereço da matricula
Funcionarios *busca_Mat(Funcionarios *lst, int matricula){
    Funcionarios *p = lst; //ponteiro auxiliar para o primeiro nó da lista

    while(p != NULL){
        if(p->matricula == matricula){
            return p;
        }
        p = p->prox;
    }

    return NULL;
}

//Função para adicionar Funcionário na lista
Funcionarios *inserir_lst(Funcionarios *lst){
    //crio um funcionario e separo memória
    Funcionarios *novo = malloc(sizeof(Funcionarios));

    //verifico se a alocação falhou
    if(novo == NULL){
        printf("Nao foi possivel adicionar o funcionario!\n");
        return lst;
    }

    //Preencho os campos do novo Funcionário
    printf("Digite o nome do Funcionario: ");
    scanf(" %99[^\n]", novo->nome);
    printf("Digite a matricula do funcionario %s: ", novo->nome);
    scanf("%d", &novo->matricula);

    //Verifico se essa matricula ja existe na lista
    if(busca_Mat(lst, novo->matricula) != NULL){
        printf("Essa matricula ja existe!\n");
        free(novo);
        return lst;
    }

    //continuo o preenchimento dos campos
    printf("Digite a idade do Funcionario: ");
    scanf("%d", &novo->idade);
    printf("Digite o salario atriubuido a %s: ", novo->nome);
    scanf("%f", &novo->salario);

    //verifico se nao existe func ou se lst.mat < novo.mat
    if(lst == NULL || lst->matricula < novo->matricula){
        novo->prox = lst;
        printf("Funcionario adicionado com sucesso!\n");
        return novo;
    }

    //percorro a lista caso haja mais de um funcionario
    Funcionarios *p = lst; //ponteiro auxiliar

    //procurando na lista
    while(p->prox != NULL && p->prox->matricula < novo->matricula){
        p = p->prox;
    }

    //Adicionando
    novo->prox = p->prox;
    p->prox = novo;

    printf("Funcionario adicionado com sucesso!\n");

    return lst;
}

//Função para remover funcionário da lista
Funcionarios *delete_lst(Funcionarios *lst){

    //verificando se a lista esta vazia
    if(lst == NULL){
        printf("Nao eh possivel remover. Lista de Funcionarios vazia!\n");
        return lst;
    }

    //pedindo a matricula do funcionario que deseja remover
    int matricula;
    printf("Digite a matricula do funcionario que deseja remover: ");
    scanf("%d", &matricula);

    //verificando se a matricula existe
    if(busca_Mat(lst, matricula) == NULL){
        printf("A matricula digitada nao corresponde a nenhum funcionario da lista!\n");
        return lst;
    }

    //Caso remova o primeiro elemento
    if(lst->matricula == matricula){
        //ponteiro auxiliar
        Funcionarios *removido = lst;
        lst = lst->prox;

        //remoção
        free(removido);

        printf("Funcionario removido com sucesso!\n");
        return lst;
    }

    //Caso o funcionário esteja no meio da lista

    //ponteiro auxiliar
    Funcionarios *p = lst;

    //percorro a lista
    while(p->prox != NULL && p->prox->matricula != matricula){
        p = p->prox;
    }

    Funcionarios *removido = p->prox; //guardo o no que sera removido

    p->prox = removido->prox;

    free(removido);

    printf("Funcionario removido com sucesso!\n");

    return lst;
}

void buscar_lst(Funcionarios *lst){
    //Verificando se a lista esta vazia
    if(lst == NULL){
        printf("Nao eh possivel buscar Funcionario. A lista está vazia!\n");
        return;
    }

    //Pedindo matricula ao usuário
    int matricula;
    printf("Digite a matricula do Funcionario que deseja buscar: ");
    scanf("%d", &matricula);

    //Verificando se a matricula existe
    Funcionarios *encontrado = busca_Mat(lst, matricula);

    if(encontrado == NULL){
        printf("A matricula digitada nao corresponde a nenhum funcionario da lista!\n");
        return;
    }

    //Caso encontre, mostra os dados
    printf("=====FUNCIONARIO ENCONTRADO=====\n");
    printf("NOME: %s\n",encontrado->nome);
    printf("MATRICULA: %d\n", encontrado->matricula);
    printf("IDADE: %d\n", encontrado->idade);
    printf("SALARIO: %.2f\n", encontrado->salario);
}

//Procedimento para mostrar a lista de funcionários cadastrados
void mostrar_lst(Funcionarios *lst){
    //Verificando se a lista esta vazia
    if(lst == NULL){
        printf("Nao ha funcionarios cadastrados na lista!\n");
        return;
    }

    Funcionarios *p = lst; //Ponteiro Auxiliar

    //Mostrando Funcionários
    printf("=====FUNCIONARIOS CADASTRADOS=====\n");
    while(p != NULL){
        printf("NOME: %s\n",p->nome);
        printf("MATRICULA: %d\n", p->matricula);
        printf("IDADE: %d\n", p->idade);
        printf("SALARIO: %.2f\n", p->salario);
        printf("\n");
        p = p->prox;
    }
}

// Função para liberar toda a lista de funcionários
void liberar_lst(Funcionarios *lst){

    Funcionarios *p = lst;
    Funcionarios *removido;

    while(p != NULL){
        removido = p;
        p = p->prox;
        free(removido);
    }

    printf("Memoria da lista liberada com sucesso!\n");
}