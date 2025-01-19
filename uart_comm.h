#ifndef UART_COMM_H
#define UART_COMM_H

#include <stddef.h> //size_t

//Funções relacionadas a comunicação serial UART
void init_uart();
void read_command(char *command, size_t size);

#endif // UART_COMM_H