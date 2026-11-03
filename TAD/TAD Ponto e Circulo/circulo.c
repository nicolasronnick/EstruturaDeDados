#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"

struct circulo {
    float raio;
    float d1;
    float d2;
};

Circulo *criar_circulo(float raio, float d1, float d2) {
    Circulo *c = malloc(sizeof(Circulo));

    if (c == NULL) {
        return NULL;
    }

    c->raio = raio;
    c->d1 = d1;
    c->d2 = d2;

    return c;
}

void acessar_circulo(Circulo *c, float *raio, float *d1, float *d2) {
    if (c != NULL) {
        *raio = c->raio;
        *d1 = c->d1;
        *d2 = c->d2;
    }
}

void atribuir_valores_circulo(Circulo *c, float raio, float d1, float d2) {
    if (c != NULL) {
        c->raio = raio;
        c->d1 = d1;
        c->d2 = d2;
    }
}

int esta_dentro_do_circulo(Circulo *c, float x, float y) {
    if (c == NULL) {
        return 0;
    }

    float distanciaX = x - c->d1;
    float distanciaY = y - c->d2;

    float distancia = distanciaX * distanciaX + distanciaY * distanciaY;

    return distancia <= c->raio * c->raio;
}

void liberar_circulo(Circulo *c) {
    if (c != NULL) {
        free(c);
    }
}