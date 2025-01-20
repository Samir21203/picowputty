#include "gpio_control.h"
#include "hardware/pwm.h"
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

// Inicialização do PWM para o buzzer
void init_pwm(uint32_t gpio) {
    // Configuração do PWM para o buzzer
    gpio_set_function(gpio, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(gpio);

    uint32_t clock_freq = 125000000; // Frequência padrão do RP2040 (125 MHz)
    uint32_t desired_freq = 1000;    // Frequência desejada para o buzzer (1 kHz)
    uint16_t divider = clock_freq / (desired_freq * 4096); // Divisor do PWM
    pwm_set_clkdiv(slice_num, divider);

    // Define a largura do pulso (50% de duty cycle)
    pwm_set_wrap(slice_num, 4095); // Resolução do PWM
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(gpio), 2048); // 50% de duty cycle

    // Habilita o PWM
    pwm_set_enabled(slice_num, true);
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
    // Acendendo o LED vermelho
    else if(strcmp(color, "RED") == 0) {
        gpio_put(LED_GREEN, 0);
        gpio_put(LED_BLUE, 0);
        gpio_put(LED_RED, 1);
    }
    // Acendendo o LED azul
    else if(strcmp(color, "BLUE") == 0) {
        gpio_put(LED_GREEN, 0);
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_RED, 0);
    }  
    // Acendendo o LED verde
    else if(strcmp(color, "GREEN") == 0) {
        gpio_put(LED_GREEN, 1);
        gpio_put(LED_BLUE, 0);
        gpio_put(LED_RED, 0);
    }
}


// Controle do buzzer
void control_buzzer(uint32_t gpio, uint32_t frequency, uint32_t duration_ms) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);

    // Atualiza a frequência do PWM
    uint32_t clock_freq = 125000000; // Frequência padrão do RP2040 (125 MHz)
    uint16_t divider = clock_freq / (frequency * 4096); // Divisor do PWM
    pwm_set_clkdiv(slice_num, divider);

    // Liga o buzzer
    pwm_set_enabled(slice_num, true);
    sleep_ms(duration_ms);

    // Desliga o buzzer
    pwm_set_enabled(slice_num, false);
}
