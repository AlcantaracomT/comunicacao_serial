# Projeto BitDogLab - Controle de Display, LED RGB e Matriz WS2812

## Descrição do Projeto

Este projeto utiliza a placa **BitDogLab** para controlar uma matriz de LEDs, um LED RGB, um display SSD1306 e botões de entrada. Os componentes utilizados são:

- **Matriz 5x5 de LEDs WS2812** (endereçáveis), conectada à GPIO 7.
- **LED RGB** com os pinos conectados às GPIOs 11, 12 e 13.
- **Botão A** conectado à GPIO 5.
- **Botão B** conectado à GPIO 6.
- **Display OLED SSD1306** conectado via I2C (GPIO 14 e GPIO 15).

## Funcionalidades do Projeto

### 1. Modificação da Biblioteca `font.h`
- Caracteres minúsculos adicionado à biblioteca `font.h`.

### 2. Entrada de Caracteres via PC
- O **Serial Monitor** do VS Code será utilizado para a entrada de caracteres.
- Cada caractere digitado será exibido no **display SSD1306** um por vez.
- Quando um **número entre 0 e 9** for digitado, um símbolo correspondente será exibido na **matriz 5x5 WS2812**.

### 3. Interação com o Botão A
- Pressionar o **Botão A** alterna o estado do **LED RGB Verde** (ligado/desligado).

### 4. Interação com o Botão B
- Pressionar o **Botão B** alterna o estado do **LED RGB Azul** (ligado/desligado).

## Requisitos
- Placa **BitDogLab**.
- Biblioteca **Pico SDK** instalada.
- Biblioteca para controle do **SSD1306**.
- Biblioteca para os **LEDs WS2812**.
- Ambiente de desenvolvimento configurado com **VS Code** e **CMake**.

## Como Executar
1. Clone o repositório:
   ```sh
   https://github.com/AlcantaracomT/comunicacao_serial.git
   ```
2. Acesse a pasta do projeto:
   ```sh
   cd comuniccao_serial
   ```
3. Compile o projeto:
   ```sh
   mkdir build && cd build
   cmake ..
   make
