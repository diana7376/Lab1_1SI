#ifndef UART_STDIO_H
#define UART_STDIO_H

#include <stdio.h>
#include <Arduino.h>

// Binds stdin/stdout to UART so printf/fgets/scanf use Serial
void initStdio();

#endif
