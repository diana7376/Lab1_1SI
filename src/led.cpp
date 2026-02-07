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

void ledBlink(int times, int delayMs) {
    for (int i = 0; i < times; i++) {
        ledOn();
        delay(delayMs);
        ledOff();
        delay(delayMs);
    }
}
