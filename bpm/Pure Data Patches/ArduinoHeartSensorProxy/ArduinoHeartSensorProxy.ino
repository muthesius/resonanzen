void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = constrain(map(analogRead(A0), 0, 1023, 0,255), 0, 255);
  Serial.write((byte)value);
}
