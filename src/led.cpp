#include "led.h"

// Logical state of the LED, used by toggle/status
static bool ledState = false;

void ledInit() {
    pinMode(LED_PIN, OUTPUT);   // configure LED pin as output
    digitalWrite(LED_PIN, LOW);
    ledState = false;
}

void ledOn() {
    digitalWrite(LED_PIN, HIGH);
    ledState = true;
}

void ledOff() {
    digitalWrite(LED_PIN, LOW);
    ledState = false;
}

void ledToggle() {
    // Toggle based on internal state
    if (ledState) {
        ledOff();
    } else {
        ledOn();
    }
}

bool ledGetState() {
    return ledState;            // expose state to serial interface
}

void ledBlink(int times, int delayMs) {
    for (int i = 0; i < times; i++) {
        ledOn();
        delay(delayMs);         // simple blocking delay for demo
        ledOff();
        delay(delayMs);
    }
}
