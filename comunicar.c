#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "oled.h"
#include "matriz_Led.h"
#include "botao.h"

int main() {
  char letra;
  stdio_init_all();

  ssd1306_t ssd;  // Estrutura do display
  oled_init(&ssd); // Inicializa o OLED

  bool cor = true;

  //matriz led e botões
  PIO pio = pio0;
  int sm = 0;
  uint offset = pio_add_program(pio, &blink_program);

  leds_init(pio, sm, offset);
  botoes_init();
  
  while (true)
  {
    scanf("%c", &letra);
    cor = !cor;

    oled_clear(&ssd, !cor); // Limpa o display
    ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo

    if (letra >= 'A' && letra <= 'Z')
    {
      apaga();
      oled_draw_char(&ssd, letra, 50, 30);
    }
    else  if (letra >= '0' && letra <= '9')
    {
      oled_draw_char(&ssd, letra, 50, 30);
      int numeral = letra - '0';
      contador(numeral);
    }
    else  if (letra >= 'a' && letra <= 'z')
    {
      apaga();
      oled_draw_char(&ssd, letra, 50, 30);
    }
    sleep_ms(500);
  }
}
