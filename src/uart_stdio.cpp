#include "uart_stdio.h"

// Function to write a character to UART (used by printf)
static int uart_putchar(char c, FILE *stream) {
    Serial.write(c);
    return 0;
}

// Function to read a character from UART (used by scanf/fgets)
static int uart_getchar(FILE *stream) {
    while (!Serial.available()) {
        // Wait for character to be available
    }
    return Serial.read();
}

// Initialize STDIO streams to work with UART
void initStdio() {
    // Create file streams for stdout and stdin
    static FILE uartout;
    static FILE uartin;
    
    // Setup stdout for printf
    fdev_setup_stream(&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
    stdout = &uartout;
    
    // Setup stdin for scanf/fgets
    fdev_setup_stream(&uartin, NULL, uart_getchar, _FDEV_SETUP_READ);
    stdin = &uartin;
}
