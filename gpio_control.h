#ifndef GPIO_CONTROL_H
#define GPIO_CONTROL_H

//Definição de pinos
#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER 21

//Funções para inicialização e controle dos GPIOs
void init_gpio();
void control_led(const char *color);
void control_buzzer();

#endif //GPIO_CONTROL_H