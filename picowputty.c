#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "gpio_control.h"
#include "uart_comm.h" 

/*
    * Este é o código principal do projeto.
*/


int main() {
    //Inicializa a UART e GPIOs
    init_uart();
    init_gpio();

    char command[10];

    while (true) {
        read_command(command, sizeof(command));

        if (strcmp(command, "BUZZER") == 0) {
            control_buzzer(BUZZER, 1000, 2000); // Liga o buzzer por 2 segundos
            printf("ON: BUZZER\n");
        } else if (strcmp(command, "OFF") == 0) {
            control_led("OFF"); // Desliga todos os LEDs
            printf("SYSTEM: OFF\n");
        } else if ((strcmp(command, "RED") == 0) || (strcmp(command, "WHITE") == 0) || (strcmp(command, "BLUE") == 0) || (strcmp(command, "GREEN") == 0)) {
            control_led(command); // Acende o LED correspondente
        } else {
            printf("SYSTEM: COMANDO INVALIDO\n"); // Comando inválido
        }
    }

    return 0;
}//fim do main