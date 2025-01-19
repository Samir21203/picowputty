#include "uart_comm.h"
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"


//Inicializa a UART
void init_uart() {
    stdio_init_all();
    printf("UART Inicializada. Aguardando comandos...\n");
}

//Lê comandos da UART
void read_command(char *command, size_t size) {
    if (fgets(command, size, stdin)) {
        command[strcspn(command, "\r\n")] = 0; // Remove caracteres de nova linha
    }
}