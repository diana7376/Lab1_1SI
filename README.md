# Lab 1.1 - User Interaction: STDIO - Serial Interface

## Author
**Student Name**: Iachim Diana
**Group**: FAF-233 
**Course**: Embedded Systems  
**Lab**: 1.1 - STDIO Serial Interface 

## Lab Objectives
Familiarization with using the STDIO library for serial communication and implementing a simple application that controls an LED through text commands transmitted from a serial terminal.

## Project Description
This project implements LED control via serial interface using text commands. The application receives commands from the terminal and responds with confirmation messages, demonstrating bidirectional communication between the microcontroller and user.
a
## Hardware Requirements
- **Microcontroller**: Arduino Mega ATmega1280
- **LED**: 1 pcs
- **Resistor**: 220Ω (1 pcs)
- **Breadboard**: 1 pcs
- **Jumper wires**: Male-to-Male
- **USB Cable**: For power and serial communication

## Circuit Diagram

### Connections
```
Arduino Mega Pin 13 → 220Ω Resistor → LED Anode (+)
LED Cathode (-) → GND
```

### Pin Configuration
- **LED_PIN**: Digital Pin 13 (has built-in LED too)
- **GND**: Any GND pin on Arduino Mega
- **Baud Rate**: 9600

## Software Setup

### Requirements
1. **Visual Studio Code** (installed)
2. **PlatformIO IDE Extension** (installed in VS Code)
3. **USB Driver** (CH340/CH341 for macOS if needed)

### Project Installation
1. Open VS Code
2. Open this folder as a PlatformIO project
3. PlatformIO will auto-detect configuration from `platformio.ini`
4. Connect Arduino Mega via USB
5. Wait for PlatformIO to download necessary dependencies

### Project Structure (Modular Design)
```
Lab1_SerialLED/
├── src/
│   ├── main.cpp          # Main program with setup() and loop()
│   └── led.cpp           # LED functions implementation
├── include/
│   └── led.h             # LED function declarations (header)
├── platformio.ini        # PlatformIO configuration
└── README.md             # Documentation (this file)
```

**Note**: Modular structure allows code reuse in future labs (LCD, Keypad, etc.).

## Available Commands

### Command List
| Command | Description | Response |
|---------|-------------|----------|
| `led on` | Turn LED on | "Confirmed: LED turned ON" |
| `led off` | Turn LED off | "Confirmed: LED turned OFF" |
| Others | Unknown command | "Error: Unknown command" |

### Command Format
- Commands are case-insensitive (`LED ON`, `led on`, `Led On` all work)
- Send command followed by Enter/Return
- System confirms each executed command

## LED Functions (Modular API)

### led.h - Public Interface
```cpp
void ledInit();          // Initialize LED pin
void ledOn();            // Turn LED on
void ledOff();           // Turn LED off
void ledToggle();        // Toggle LED state
bool ledGetState();      // Return current state
```

### Usage in Other Modules
```cpp
#include "led.h"

void setup() {
    ledInit();
    ledOn();  // LED on
}
```

## Build and Upload

### Steps
1. **Build**: Click ✓ (checkmark) in VS Code bottom bar
   - Or: `Ctrl+Alt+B` / `Cmd+Option+B`
2. **Upload**: Click → (arrow) in bottom bar
   - Or: `Ctrl+Alt+U` / `Cmd+Option+U`
3. **Serial Monitor**: Click 🔌 (plug) in bottom bar
   - Or: `Ctrl+Alt+S` / `Cmd+Option+S`

### Port Verification (macOS)
If Arduino is not auto-detected:
```bash
ls /dev/cu.*
```
Look for:
- `/dev/cu.usbserial-*`
- `/dev/cu.usbmodem-*`
- `/dev/cu.wchusbserial-*`

Uncomment in `platformio.ini`:
```ini
upload_port = /dev/cu.usbserial-XXXXX
```

## Testing

### Functional Test
1. Upload code to Arduino Mega
2. Open Serial Monitor (9600 baud)
3. Observe message: "System ready."
4. Type `led on` → Enter
   - ✓ LED turns on
   - ✓ Message: "Confirmed: LED turned ON"
5. Type `led off` → Enter
   - ✓ LED turns off
   - ✓ Message: "Confirmed: LED turned OFF"
6. Type invalid command → Enter
   - ✓ Message: "Error: Unknown command"

### Physical Hardware Test
- Verify external LED turns on/off in sync with built-in LED (pin 13)
- Verify 220Ω resistor is connected correctly
- Verify LED doesn't overheat


## References
- [PlatformIO Documentation](https://docs.platformio.org/)
- [Arduino Reference](https://www.arduino.cc/reference/en/)
- [Arduino Mega Pinout](https://docs.arduino.cc/hardware/mega-2560/)
- Lab 1.1 Assignment - UTM ELSE Platform
