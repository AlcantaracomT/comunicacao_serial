#ifndef MATRIZ_LED
#define MATRIZ_LED

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "blink.pio.h"
#include <string.h>

// Definições
#define IS_RGBW false
#define NUM_PIXELS 25
#define WS2812_PIN 7

#define LED_RED 13
#define LED_GREEN 11
#define LED_BLUE 12

// Variáveis globais para cores
extern uint8_t led_r, led_g, led_b;
extern bool led_buffer[NUM_PIXELS];

// Inicializa os LEDs
void leds_init(PIO pio, int sm, uint offset);

// Define um LED RGB
void set_led_color(uint red_pin, uint green_pin, uint blue_pin, bool R, bool G, bool B);

// Atualiza a matriz de LEDs WS2812
void set_one_led(uint8_t r, uint8_t g, uint8_t b, double inten);

// Converte RGB para GRB
static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b);

//atualiza na matriz
void contador(int contar);

//apagar matriz de led
void apaga();

#endif // MATRIZ_LED