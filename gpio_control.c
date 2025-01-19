#include "gpio_control.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <string.h>

//Inicializa os GPIOs
void init_gpio()
{

}

//Controle dos LEDs
void control_led(const char *color) {
    //Acendendo a led verde
    if (strcmp(color, "GREEN") == 0) {
        gpio_put(LED_GREEN, 1);
        gpio_put(LED_BLUE, 0);
        gpio_put(LED_RED, 0);
    } 


    /*Outras LEDs aqui*/
}

//Controle do buzzer
void control_buzzer() {

}