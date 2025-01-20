#include "gpio_control.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <string.h>

void init_gpio() {
    // Configurando os pinos dos LEDs como saída
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    // Configurando o pino do buzzer como saída
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);

    // Garantir que todos os LEDs e o buzzer comecem desligados
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_RED, 0);
    gpio_put(BUZZER, 0);
}

// Controle dos LEDs
void control_led(const char *color) {
    // Acendendo o LED verde
    if (strcmp(color, "WHITE") == 0) {
        gpio_put(LED_GREEN, 1);
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_RED, 1);
    }
    // Desligando todos os LEDs
    else if (strcmp(color, "OFF") == 0) {
        gpio_put(LED_GREEN, 0);
        gpio_put(LED_BLUE, 0);
        gpio_put(LED_RED, 0);
    }
}


// Controle do buzzer
void control_buzzer() {
    gpio_put(BUZZER, 1); // Liga o buzzer
    sleep_ms(2000);      // Mantém ligado por 2 segundos
    gpio_put(BUZZER, 0); // Desliga o buzzer
}

//Controle do buzzer
void control_buzzer() {

}