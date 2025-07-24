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
