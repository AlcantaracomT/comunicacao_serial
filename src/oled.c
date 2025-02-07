#include "include/oled.h"

void oled_init(ssd1306_t *ssd) {
    // Inicializa o I2C
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    // Inicializa o OLED
    ssd1306_init(ssd, WIDTH, HEIGHT, false, OLED_ADDRESS, I2C_PORT);
    ssd1306_config(ssd);
    ssd1306_send_data(ssd);
    
    // Limpa a tela inicialmente
    oled_clear(ssd, false);
}

void oled_clear(ssd1306_t *ssd, bool color) {
    ssd1306_fill(ssd, color);
    ssd1306_send_data(ssd);
}

void oled_draw_char(ssd1306_t *ssd, char letra, uint8_t x, uint8_t y) {
    ssd1306_draw_string(ssd, &letra, x, y);
    ssd1306_send_data(ssd);
}
