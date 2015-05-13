// Resonanzen v1.0
// Arduino Firmware

const int LED = 2;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  
  digitalWrite(LED, HIGH);
  delay(1000);
  
  digitalWrite(LED, LOW);
  delay(1000);
}
