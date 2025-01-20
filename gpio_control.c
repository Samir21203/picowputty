#include "pico/stdlib.h"
#include "gpio_control.h"
#include "hardware/pwm.h"
#include "hardware/gpio.h"
#include <string.h>
#include <stdio.h>
#include "hardware/timer.h"


#define BUZZER_FREQUENCY 500

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


static void buzzer_set_frequency(uint gpio, uint frequency)
{
    // Obter o slice do PWM para o GPIO
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    // Configurar a frequência
    uint32_t clock_freq = 125000000; // Frequência do clock (125 MHz no Pico)
    uint32_t divider = clock_freq / (frequency * 65536); // Divisor para a frequência desejada
    if (divider < 1)
        divider = 1; // Evitar divisão menor que 1
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, divider); // Configurar o divisor do clock
    pwm_init(slice_num, &config, true); // Iniciar o PWM
    // Configurar a duty cycle (50% para som contínuo)
    pwm_set_gpio_level(gpio, 32768); // Meio do ciclo (50%)
}



// Inicialização do PWM para o buzzer
void buzzer_init(uint buzzer_pin){
    gpio_init(buzzer_pin);
    gpio_set_dir(buzzer_pin, GPIO_OUT);
    // Configurar o GPIO para PWM
    gpio_set_function(buzzer_pin, GPIO_FUNC_PWM); 
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

void buzzer_beep(uint buzzer_pin, uint duration){
    buzzer_set_frequency(buzzer_pin, BUZZER_FREQUENCY);
    sleep_ms(duration);
    pwm_set_gpio_level(buzzer_pin, 0);
 }
