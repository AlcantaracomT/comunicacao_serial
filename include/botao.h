#ifndef BOTAO_H
#define BOTAO_H

#include "pico/stdlib.h"

// pinos rgb
#define RED_LED 13
#define GREEN_LED 11
#define BLUE_LED 12

// Definições dos botões
#define BOTAO1 5
#define BOTAO2 6

// Inicializa os botões
void botoes_init(void);

// Interrupção dos botões
static void interrupcao(uint gpio, uint32_t events);


#endif // BOTAO_H
