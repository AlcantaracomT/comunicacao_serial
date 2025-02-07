#include "include/botao.h"
#include <stdio.h>
#include <string.h>
#include "include/oled.h"

int numeral = 0;
static absolute_time_t last_interrupt_time_botao1 = 0;
static absolute_time_t last_interrupt_time_botao2 = 0;
static const uint64_t debounce_time_ms = 200;

extern ssd1306_t ssd;  // O objeto do display deve estar declarado em outro arquivo

void botoes_init(void) {

    gpio_init(RED_LED);
    gpio_init(BLUE_LED);
    gpio_init(GREEN_LED);

    gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_set_dir(BLUE_LED, GPIO_OUT);
    gpio_set_dir(GREEN_LED, GPIO_OUT);

    gpio_init(BOTAO1);
    gpio_init(BOTAO2);

    gpio_pull_up(BOTAO1);
    gpio_pull_up(BOTAO2);

    gpio_set_dir(BOTAO1, GPIO_IN);
    gpio_set_dir(BOTAO2, GPIO_IN);

    gpio_set_irq_enabled_with_callback(BOTAO1, GPIO_IRQ_EDGE_FALL, true, &interrupcao);
    gpio_set_irq_enabled_with_callback(BOTAO2, GPIO_IRQ_EDGE_FALL, true, &interrupcao);
}

// Função de interrupção dos botões
static void interrupcao(uint gpio, uint32_t events) {
 
    absolute_time_t current_time = get_absolute_time();

    if (gpio == BOTAO1) 
    { 
        if (absolute_time_diff_us(last_interrupt_time_botao1, current_time) < debounce_time_ms * 1000) return;

        last_interrupt_time_botao1 = current_time;
        gpio_put(RED_LED, 0);
        gpio_put(GREEN_LED, !gpio_get(GREEN_LED));
        gpio_put(BLUE_LED, 0);
        if(gpio_get(GREEN_LED))
        {
            printf("Led verde Ligado\n");
            ssd1306_draw_string(&ssd, "Led Verde ", 8, 30);
            ssd1306_draw_string(&ssd, "Ligado   ", 8, 40);
            ssd1306_send_data(&ssd);
        }
        else
        {
            printf("Led verde desligado\n");
            ssd1306_draw_string(&ssd, "Led Verde ", 8, 30);
            ssd1306_draw_string(&ssd, "Desligado", 8, 40);
            ssd1306_send_data(&ssd);
        }
    } 
    else if(gpio == BOTAO2) 
    { 
        if (absolute_time_diff_us(last_interrupt_time_botao2, current_time) < debounce_time_ms * 1000) return;

        last_interrupt_time_botao2 = current_time;
        gpio_put(RED_LED, 0);
        gpio_put(GREEN_LED, 0);
        gpio_put(BLUE_LED, !gpio_get(BLUE_LED));

        if(gpio_get(BLUE_LED))
        {
            printf("Led azul Ligado\n");
            ssd1306_draw_string(&ssd, "Led Azul ", 8, 30);
            ssd1306_draw_string(&ssd, "Ligado   ", 8, 40);
            ssd1306_send_data(&ssd);
        }
        else 
        {
            printf("Led azul desligado\n");
            ssd1306_draw_string(&ssd, "Led Azul", 8, 30);
            ssd1306_draw_string(&ssd, "Desligado", 8, 40);
            ssd1306_send_data(&ssd);
        }
    }
}
