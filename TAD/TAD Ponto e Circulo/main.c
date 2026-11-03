
#include <stdio.h>
#include "ponto.h"
#include "circulo.h"

int main() {

    // =====================================
    // TESTANDO O TAD PONTO
    // =====================================

    printf("===== TAD PONTO =====\n");

    // Criando dois pontos
    Ponto *p1 = criar_ponto(2, 3);
    Ponto *p2 = criar_ponto(5, 7);

    if (p1 == NULL || p2 == NULL) {
        printf("Erro ao criar os pontos!\n");
        liberar_ponto(p1);
        liberar_ponto(p2);
        return 1;
    }

    // Acessando as coordenadas do primeiro ponto
    float x, y;

    acessar_ponto(p1, &x, &y);

    printf("Ponto 1: (%.2f, %.2f)\n", x, y);

    // Calculando a distancia entre os pontos
    float distancia = calcular_dst(p1, p2);

    printf("Distancia entre os pontos: %.2f\n", distancia);

    // Alterando as coordenadas do primeiro ponto
    atribuir_valores(p1, 4, 6);

    acessar_ponto(p1, &x, &y);

    printf("Ponto 1 apos alteracao: (%.2f, %.2f)\n", x, y);

    // Liberando a memoria dos pontos
    liberar_ponto(p1);
    liberar_ponto(p2);


    // =====================================
    // TESTANDO O TAD CIRCULO
    // =====================================

    printf("\n===== TAD CIRCULO =====\n");

    // Criando um circulo com raio 5 e centro (2, 3)
    Circulo *c = criar_circulo(5, 2, 3);

    if (c == NULL) {
        printf("Erro ao criar o circulo!\n");
        return 1;
    }

    // Acessando os dados do circulo
    float raio, centroX, centroY;

    acessar_circulo(c, &raio, &centroX, &centroY);

    printf("Raio: %.2f\n", raio);
    printf("Centro: (%.2f, %.2f)\n", centroX, centroY);

    // Alterando os valores do circulo
    atribuir_valores_circulo(c, 8, 4, 6);

    acessar_circulo(c, &raio, &centroX, &centroY);

    printf("\nCirculo apos alteracao:\n");
    printf("Raio: %.2f\n", raio);
    printf("Centro: (%.2f, %.2f)\n", centroX, centroY);

    // Verificando se um ponto esta dentro do circulo
    int resultado = esta_dentro_do_circulo(c, 5, 7);

    if (resultado == 1) {
        printf("\nO ponto (5, 7) esta dentro do circulo.\n");
    } else {
        printf("\nO ponto (5, 7) esta fora do circulo.\n");
    }

    // Liberando a memoria do circulo
    liberar_circulo(c);

    return 0;
}
