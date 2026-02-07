#include <Arduino.h>
#include "led.h"

void setup() {
    Serial.begin(9600);
    ledInit();
    Serial.println("System ready.");
    Serial.println("Available commands:");
    Serial.println("  - led on");
    Serial.println("  - led off");
}

void loop() {
    if (Serial.available() > 0) {
        String command = Serial.readStringUntil('\n');
        command.trim();
        command.toLowerCase();

        if (command == "led on") {
            ledOn();
            Serial.println("Confirmed: LED turned ON");
        } 
        else if (command == "led off") {
            ledOff();
            Serial.println("Confirmed: LED turned OFF");
        }
        else if (command.length() > 0) {
            Serial.println("Error: Unknown command");
            Serial.println("Use 'led on' or 'led off'");
        }
    }
}