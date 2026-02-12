#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "led.h"
#include "uart_stdio.h"

void setup() {
    Serial.begin(9600);       // UART speed
    initStdio();              // map STDIO ↔ UART
    ledInit();                // prepare LED peripheral

    // Initial banner + command menu via printf (STDIO)
    printf("\n=================================\n");
    printf(" LED Control System v1.0\n");
    printf("=================================\n");
    printf("System ready.\n\n");
    printf("Available commands:\n");
    printf(" - led on      : Turn LED on\n");
    printf(" - led off     : Turn LED off\n");
    printf(" - led toggle  : Toggle LED state\n");
    printf(" - led status  : Get LED status\n");
    printf(" - led blink   : Blink LED 3 times\n");
    printf(" - help        : Show this menu\n");
    printf("=================================\n\n");
    printf("> ");                // prompt for first command
}

void loop() {
    // IDLE → RECEIVING when data is available
    if (Serial.available() > 0) {
        char buffer[32];

        // Read one command line via STDIO
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            buffer[strcspn(buffer, "\r\n")] = 0; // strip newline

            // Normalize to lowercase for case‑insensitive comparison
            for (int i = 0; buffer[i]; i++) {
                buffer[i] = (char)tolower((unsigned char)buffer[i]);
            }

            // === Critical area: command parsing and execution ===
            if (strcmp(buffer, "led on") == 0) {
                ledOn();
                printf("[OK] LED turned ON\n");

            } else if (strcmp(buffer, "led off") == 0) {
                ledOff();
                printf("[OK] LED turned OFF\n");

            } else if (strcmp(buffer, "led toggle") == 0) {
                ledToggle();
                printf("[OK] LED toggled. Current state: %s\n",
                       ledGetState() ? "ON" : "OFF");

            } else if (strcmp(buffer, "led status") == 0) {
                printf("[INFO] LED is currently: %s\n",
                       ledGetState() ? "ON" : "OFF");

            } else if (strcmp(buffer, "led blink") == 0) {
                printf("Blinking LED 3 times...\n");
                ledBlink(3, 500);
                printf("[OK] Blink complete\n");

            } else if (strcmp(buffer, "help") == 0) {
                // Reprint help menu
                printf("\n=================================\n");
                printf(" LED Control System - Help\n");
                printf("=================================\n");
                printf("Available commands:\n");
                printf(" led on      - Turn LED on\n");
                printf(" led off     - Turn LED off\n");
                printf(" led toggle  - Toggle LED state\n");
                printf(" led status  - Get LED status\n");
                printf(" led blink   - Blink LED 3 times\n");
                printf(" help        - Show this menu\n");
                printf("=================================\n\n");

            } else if (strlen(buffer) > 0) {
                // Any other non‑empty text is treated as unknown command
                printf("[ERROR] Unknown command: '%s'\n", buffer);
                printf("[INFO] Type 'help' for available commands\n");
            }

            printf("> "); // prompt for next command
        }
    }
}
