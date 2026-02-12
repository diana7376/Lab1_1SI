#include "uart_stdio.h"
#include <stdio.h>
#include <Arduino.h>

// Output function used by printf
static int uart_putchar(char c, FILE *stream) {
    (void)stream;
    Serial.write(c);
    return 0;
}

// Input function used by fgets/scanf
static int uart_getchar(FILE *stream) {
    (void)stream;

    // busy-wait until a character arrives
    while (!Serial.available()) {
        // spin
    }

    int c = Serial.read();        // use int (required by libc prototypes)

    // echo everything except CR/LF
    if (c != '\r' && c != '\n') {
        Serial.write((char)c);
    }

    // return the character to scanf/fgets
    return c;
}

void initStdio() {
    static FILE uartout;
    static FILE uartin;

    // stdout → uart_putchar (printf)
    fdev_setup_stream(&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
    stdout = &uartout;

    // stdin → uart_getchar (fgets/scanf)
    fdev_setup_stream(&uartin, NULL, uart_getchar, _FDEV_SETUP_READ);
    stdin = &uartin;
}
