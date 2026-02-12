#ifndef LED_H
#define LED_H

#include <Arduino.h>

// Must match the pin used in the electric schematic
#define LED_PIN 13

void ledInit();
void ledOn();
void ledOff();
void ledToggle();
bool ledGetState();
void ledBlink(int times, int delayMs);

#endif
