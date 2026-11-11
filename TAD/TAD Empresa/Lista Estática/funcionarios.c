#include "funcionarios.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//PROCEDIMENTOS PARA LIMPAR E PAUSAR 
void limpar(void){
    system("cls");
}

void pause_continue(void){
    system("pause");
}

//CAMPOS DA ESTRUTURA
struct funcionarios{
    char nome[100];
    int matricula;
    int idade;
    float salario;
};

//variaveis e ponteiros para a manipulação
static Funcionarios lista[MAX]; //vetor de funcionarios
static Funcionarios *ptr = lista; //ponteiro para o primeiro funcionario da lista
static int quantidade = 0; //controlar a quantidade de funcionarios
static int *qtd = &quantidade; //ponteiro para quantidade, facilitar a manipulação

//FUNÇÕES DE VERIFICAÇÃO
//retorna se a lista esta vazia
int lst_vazia(void){
    return *qtd == 0;
}

//retorna se a lista esta cheia
int lst_cheia(void){
    return *qtd >= MAX;
}

//verificando se ja existe tal matricula na lista
static int lst_matricula(int matricula){
    int i;
    for(i=0; i<*qtd; i++){
        if(matricula == ptr[i].matricula){
            return i; //matricula ja existe
        }
    }

    return -1; //matricula nao existe
}

//FUNÇÕES PARA A MANIPULAÇÃO DA LISTA
//procedimento para adicionar um funcionario na lista
void lst_insere(void){
    //verificando se a lista nao esta cheia
    if(lst_cheia()){
        printf("Nao eh possivel adicionar funcionario, pois a lista ja esta cheia!\n");
        pause_continue();
        return;
    }

    //preenchendo campos
    printf("Digite o nome do funcionario que deseja adicionar: ");
    scanf(" %99[^\n]", ptr[*qtd].nome);

    printf("Agora digite a matricula do funcionario %s: ", ptr[*qtd].nome);
    scanf("%d", &ptr[*qtd].matricula);

    //verificando se ja existe tal matricula
    if(lst_matricula(ptr[*qtd].matricula) != -1){
        printf("A matricula ja eh referente a outro funcionario!\n");
        pause_continue();
        return;
    }

    //continuando preenchimento dos campos
    printf("Digite a idade do funcionario novo: ");
    scanf("%d", &ptr[*qtd].idade);

    printf("Por ultimo, digite o salario que %s ira receber: ", ptr[*qtd].nome);
    scanf("%f", &ptr[*qtd].salario);

    (*qtd)++;

    printf("Funcionario Adicionado com Sucesso!\n");
    pause_continue();
}

// função para remover funcionário da lista
void lst_remove(void){
    if(lst_vazia()){
        printf("Nao eh possivel remover funcionario, pois a lista esta vazia!\n");
        pause_continue();
        return;
    }

    // pedindo matricula do funcionario
    int mat_remove;

    printf("Digite a matricula do funcionario que deseja remover: ");
    scanf("%d", &mat_remove);

    // verificando se a matricula existe na lista
    int indice = lst_matricula(mat_remove);

    if(indice == -1){
        printf("A matricula digitada nao existe na lista!\n");
        pause_continue();
        return;
    }

    // deslocando os elementos para a esquerda
    for(int i = indice; i < *qtd - 1; i++){
        ptr[i] = ptr[i + 1];
    }

    // atualizando a quantidade de funcionarios
    (*qtd)--;

    printf("Funcionario removido com sucesso!\n");
    pause_continue();
}

//função para buscar funcionário na lista
void lst_busca(void){
    //verificando se a lista esta vazia
    if(lst_vazia()){
        printf("Nao eh possivel buscar nenhum funcionario, pois a lista esta vazia\n");
        pause_continue();
        return;
    }

    //pedindo matricula do funcionário desejado pela busca
    int mat_buscada;
    printf("Digite a matricula do funcionario que deseja buscar: ");
    scanf("%d", &mat_buscada);

    int indice = lst_matricula(mat_buscada);
    //verificando se a matricula digitada existe na lista
    if(indice == -1){
        printf("Nao foi encontrado nenhum funcionario com a matricula digitada!\n");
        pause_continue();
        return;
    }

    printf("----------FUNCIONARIO ENCONTRADO----------\n");
    printf("NOME: %s\n", ptr[indice].nome);
    printf("MATRICULA: %d\n", ptr[indice].matricula);
    printf("IDADE: %d\n", ptr[indice].idade);
    printf("SALARIO: %.2f\n", ptr[indice].salario);

    pause_continue();
}

//função para mostrar os funcionários cadastrados na lista
void lst_mostrar(void){
    //verificando se a list esta vazia
    if(lst_vazia()){
        printf("Nao ha nenhum funcionario cadastrado na lista!\n");
        pause_continue();
        return;
    }

    printf("----------FUNCIONARIOS CADASTRADOS----------\n");
    int i;
    for(i=0; i<*qtd; i++){
        printf("NOME: %s\n", ptr[i].nome);
        printf("MATRICULA: %d\n", ptr[i].matricula);
        printf("IDADE: %d\n", ptr[i].idade);
        printf("SALARIO: %.2f\n", ptr[i].salario);
        printf("\n");
    }
    pause_continue();
}