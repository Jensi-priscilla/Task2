# Task2
# 🔌 Arduino Serial Home Automation – Light, Bulb & Fan Control

This Tinkercad-based Arduino Uno project allows controlling **a light**, **a bulb**, and **a fan (DC motor)** using serial commands. The Serial Monitor acts as a basic user interface to turn components ON and OFF.

---

## 🧰 Components Used

| Component      | Quantity |
|----------------|----------|
| Arduino Uno    | 1        |
| LED (Light)    | 1        |
| LED (Bulb)     | 1        |
| DC Motor       | 1        |
| Resistors (220Ω for LEDs) | 2 |
| Jumper Wires   | As needed |

---

## 🔌 Circuit Connections

| Arduino Pin | Connected Component | Description       |
|-------------|---------------------|-------------------|
| D2          | Light LED (+)       | Simulates a light |
| D3          | Bulb LED (+)        | Simulates a bulb  |
| D5          | DC Motor Terminal   | Fan motor         |
| GND         | All component GNDs  | Ground connection |

---

## 🧠 Serial Commands

Use the **Serial Monitor** (baud rate: **9600**) to send single-character commands to control components:

| Command | Action         |
|---------|----------------|
| `A`     | Light ON       |
| `a`     | Light OFF      |
| `B`     | Bulb ON        |
| `b`     | Bulb OFF       |
| `C`     | Fan ON         |
| `c`     | Fan OFF        |

---

## 💻 Arduino Code

```cpp
int lightPin = 2;
int bulbPin = 3;
int fanPin = 5;
char command;

void setup() {
  pinMode(lightPin, OUTPUT);
  pinMode(bulbPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();

    switch(command) {
      case 'A': digitalWrite(lightPin, HIGH); Serial.println("Light ON"); break;
      case 'a': digitalWrite(lightPin, LOW); Serial.println("Light OFF"); break;

      case 'B': digitalWrite(bulbPin, HIGH); Serial.println("Bulb ON"); break;
      case 'b': digitalWrite(bulbPin, LOW); Serial.println("Bulb OFF"); break;

      case 'C': digitalWrite(fanPin, HIGH); Serial.println("Fan ON"); break;
      case 'c': digitalWrite(fanPin, LOW); Serial.println("Fan OFF"); break;

      default: Serial.println("Invalid command"); break;
    }
  }
}
