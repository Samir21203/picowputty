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
void init_pwm(uint32_t gpio);
void control_buzzer(uint32_t gpio, uint32_t frequency, uint32_t duration_ms);

#endif //GPIO_CONTROL_H