#ifndef CIRCULO_H
#define CIRCULO_H

typedef struct circulo Circulo;

Circulo *criar_circulo(float raio, float d1, float d2);
void acessar_circulo(Circulo *c, float *raio, float *d1, float *d2);
void atribuir_valores_circulo(Circulo *c, float raio, float d1, float d2);
int esta_dentro_do_circulo(Circulo *c, float x, float y);
void liberar_circulo(Circulo *c);

#endif