// Resonanzen v1.0
// Arduino Firmware

void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  
  digitalWrite(2, HIGH);
  delay(1000);
  
  digitalWrite(3, LOW);
  delay(1000);
}
