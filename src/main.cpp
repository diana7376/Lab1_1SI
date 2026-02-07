#include <Arduino.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "led.h"
#include "uart_stdio.h"

void setup() {
    // Initialize serial communication
    Serial.begin(9600);
    
    // Initialize STDIO library for printf/scanf
    initStdio();
    
    // Initialize LED
    ledInit();
    
    // Print welcome message using printf
    printf("\n=================================\n");
    printf("  LED Control System v1.0\n");
    printf("=================================\n");
    printf("System ready.\n");
    printf("\nAvailable commands:\n");
    printf("  - led on        : Turn LED on\n");
    printf("  - led off       : Turn LED off\n");
    printf("  - led toggle    : Toggle LED state\n");
    printf("  - led status    : Get LED status\n");
    printf("  - led blink     : Blink LED 3 times\n");
    printf("  - help          : Show this menu\n");
    printf("=================================\n\n");
    printf("> ");
}

void loop() {
    if (Serial.available() > 0) {
        char buffer[32];
        
        // Read command using fgets (STDIO function)
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Remove newline character
            buffer[strcspn(buffer, "\r\n")] = 0;
            
            // Convert to lowercase for case-insensitive comparison
            for (int i = 0; buffer[i]; i++) {
                buffer[i] = tolower(buffer[i]);
            }
            
            // Parse and execute commands
            if (strcmp(buffer, "led on") == 0) {
                ledOn();
                printf("[OK] LED turned ON\n");
            }
            else if (strcmp(buffer, "led off") == 0) {
                ledOff();
                printf("[OK] LED turned OFF\n");
            }
            else if (strcmp(buffer, "led toggle") == 0) {
                ledToggle();
                printf("[OK] LED toggled. Current state: %s\n", 
                       ledGetState() ? "ON" : "OFF");
            }
            else if (strcmp(buffer, "led status") == 0) {
                printf("[INFO] LED is currently: %s\n", 
                       ledGetState() ? "ON" : "OFF");
            }
            else if (strcmp(buffer, "led blink") == 0) {
                printf("Blinking LED 3 times...\n");
                ledBlink(3, 500);  // Blink 3 times, 500ms delay
                printf("[OK] Blink complete\n");
            }
            else if (strcmp(buffer, "help") == 0) {
                printf("\n=================================\n");
                printf("  LED Control System - Help\n");
                printf("=================================\n");
                printf("Available commands:\n");
                printf("  led on        - Turn LED on\n");
                printf("  led off       - Turn LED off\n");
                printf("  led toggle    - Toggle LED state\n");
                printf("  led status    - Get LED status\n");
                printf("  led blink     - Blink LED 3 times\n");
                printf("  help          - Show this menu\n");
                printf("=================================\n\n");
            }
            else if (strlen(buffer) > 0) {
                printf("[ERROR] Unknown command: '%s'\n", buffer);
                printf("[INFO] Type 'help' for available commands\n");
            }
            
            // Print prompt for next command
            printf("> ");
        }
    }
}
