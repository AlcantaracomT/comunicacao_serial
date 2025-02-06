#ifndef OLED_H
#define OLED_H

#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "ssd1306.h"

// Definições do I2C e do OLED
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define OLED_ADDRESS 0x3C

// Inicializa o display OLED
void oled_init(ssd1306_t *ssd);

// Limpa o display OLED
void oled_clear(ssd1306_t *ssd, bool color);

// Desenha um caractere no display
void oled_draw_char(ssd1306_t *ssd, char letra, uint8_t x, uint8_t y);

#endif // OLED_H
