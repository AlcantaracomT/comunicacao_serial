#include "include/matriz_Led.h"

// Variáveis globais para cores
uint8_t led_r = 255;
uint8_t led_g = 255;
uint8_t led_b = 0;

// Buffer para armazenar quais LEDs estão acesos
bool led_buffer[NUM_PIXELS];

void leds_init(PIO pio, int sm, uint offset) {
    // Inicializa o PIO para os LEDs blink
    blink_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    // Inicializa os LEDs RGB
    gpio_init(LED_RED);
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);

    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
}

// Define a cor do LED RGB
void set_led_color(uint red_pin, uint green_pin, uint blue_pin, bool R, bool G, bool B) {
    gpio_put(red_pin, R);   
    gpio_put(green_pin, G); 
    gpio_put(blue_pin, B); 
}

// Enviar dados para o LED blink
static inline void put_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

// Converte RGB para GRB
static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return ((uint32_t)(r) << 8) | ((uint32_t)(g) << 16) | (uint32_t)(b);
}

// Atualiza os LEDs blink
void set_one_led(uint8_t r, uint8_t g, uint8_t b, double inten) {
    r *= inten;
    g *= inten;
    b *= inten;
    uint32_t color = urgb_u32(r, g, b);

    for (int i = 0; i < NUM_PIXELS; i++) {
        put_pixel(led_buffer[i] ? color : 0);
    }
}

//atualiza na matriz

void contador(int contar) {
    bool numeros[10][NUM_PIXELS] = { 
        {0, 1, 1, 1, 0,0, 1, 0, 1, 0,0, 1, 0, 1, 0,0, 1, 0, 1, 0,0, 1, 1, 1, 0},     //0
        {0, 0, 1, 0, 0,0, 0, 1, 0, 0,0, 0, 1, 0, 0,0, 1, 1, 0, 0,0, 0, 1, 0, 0},     //1
        {0, 1, 1, 1, 0,0, 1, 0, 0, 0,0, 1, 1, 1, 0,0, 0, 0, 1, 0,0, 1, 1, 1, 0},     //2
        {0, 1, 1, 1, 0,0, 0, 0, 1, 0,0, 1, 1, 1, 0,0, 0, 0, 1, 0,0, 1, 1, 1, 0},     //3
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1,0},  //4
        {0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1,0},  //5
        {0, 1, 1, 1, 0,0, 1, 0, 1, 0,0, 1, 1, 1, 0,0, 1, 0, 0, 0,0, 1, 1, 1, 0},     //6
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1,0},  //7
        {0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1,0},  //8
        {0, 1, 0, 0, 0, 0,0, 0, 1, 0, 0, 1, 1, 1, 0,0, 1, 0, 1, 0,0, 1, 1, 1, 0}     //9   
    };

    memcpy(led_buffer, numeros[contar], NUM_PIXELS * sizeof(bool));
    set_one_led(led_r, led_g, led_b, 0.5);
}

void apaga()
{
    for (int i = 0; i < NUM_PIXELS; i++) {
        put_pixel(0);
    }
}