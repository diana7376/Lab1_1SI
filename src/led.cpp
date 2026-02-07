#include "led.h"

static bool ledState = false;

void ledInit() {
    pinMode(LED_PIN, OUTPUT);
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
    if (ledState) {
        ledOff();
    } else {
        ledOn();
    }
}

bool ledGetState() {
    return ledState;
}