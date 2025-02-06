#include "botao.h"
#include "matriz_Led.h"
#include <stdio.h>
#include <string.h>

int numeral = 0;
static absolute_time_t last_interrupt_time_botao1 = 0;
static absolute_time_t last_interrupt_time_botao2 = 0;
static const uint64_t debounce_time_ms = 200;

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
    int b1 = 0;
    int b2 = 0;
    absolute_time_t current_time = get_absolute_time();

    if (gpio == BOTAO1 && b1 == 0) 
    { 
        if (absolute_time_diff_us(last_interrupt_time_botao1, current_time) < debounce_time_ms * 1000) return;
        gpio_put(RED_LED, 0);
        gpio_put(GREEN_LED, !gpio_get(GREEN_LED));
        gpio_put(BLUE_LED, 0);
        b1 = 1;
    } 
    else if(gpio == BOTAO2 && b2 == 0) 
    { 
        if (absolute_time_diff_us(last_interrupt_time_botao2, current_time) < debounce_time_ms * 1000) return;
        gpio_put(RED_LED, 0);
        gpio_put(GREEN_LED, 0);
        gpio_put(BLUE_LED, !gpio_get(BLUE_LED));
        b2 = 1;
    }
}
