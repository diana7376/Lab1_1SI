#ifndef LED_H
#define LED_H

#include <Arduino.h>

// LED pin definition
#define LED_PIN 13

// Function declarations
void ledInit();
void ledOn();
void ledOff();
void ledToggle();
bool ledGetState();

#endif