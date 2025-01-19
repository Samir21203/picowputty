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

        //Implemente o controle dos LEDs e buzzer aqui
    }
}
