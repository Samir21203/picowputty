#include <stdio.h>
#include "pico/stdlib.h"
#include "gpio_control.h"
#include "uart_comm.h" 

/*
    * Este é o código principal do projeto.
 */


int main()
{
    //Inicializa a UART e GPIOs
    init_uart();
    init_gpio();

    char command[10];

    while (true) {
        read_command(command, sizeof(command));

        if (strcmp(command, "WHITE") == 0) {
            control_led("WHITE"); // Liga todos os LEDs (luz branca)
            printf("LED Branco (todos ligados) ligado\n");
        } else if (strcmp(command, "OFF") == 0) {
            control_led("OFF"); // Desliga todos os LEDs
            printf("Todos os LEDs desligados\n");
        }else {
            printf("Comando inválido: %s\n", command);
        }
}
