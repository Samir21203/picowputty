#ifndef GPIO_CONTROL_H
#define GPIO_CONTROL_H

//Definição de pinos
#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER 21

#include <stdint.h>

//Funções para inicialização e controle dos GPIOs
void init_gpio();
void control_led(const char *color);

//Funções para controle do PWM no buzzer
static void buzzer_set_frequency(uint buzzer_pin, uint frequency);
void buzzer_init(uint buzzer_pin);
void buzzer_beep(uint buzzer_pin, uint duration);

#endif //GPIO_CONTROL_H