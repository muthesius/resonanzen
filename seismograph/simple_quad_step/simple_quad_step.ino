/*
  Simple Sketch for Sparkfuns QuadStepper Driver
 */
const int step_pin  = 5;
const int one_pin   = 6;
const int two_pin   = 7;
const int three_pin = 9;
const int four_pin  = 10;
const int dir_pin   = 11;

const int torque = 1;
#define STEPMIN 300

const int steptime = STEPMIN + (torque * 260);

void setup() {
  pinMode(A0,INPUT_PULLUP);
  
  // put your setup code here, to run once:
  pinMode(step_pin, OUTPUT);
  pinMode(one_pin, OUTPUT);
  pinMode(two_pin, OUTPUT);
  pinMode(three_pin, OUTPUT);
  pinMode(four_pin, OUTPUT);
  pinMode(dir_pin, OUTPUT);

  digitalWrite(step_pin, LOW);
  digitalWrite(one_pin, LOW); // eins an!
  digitalWrite(two_pin, HIGH);
  digitalWrite(three_pin, HIGH);
  digitalWrite(four_pin, HIGH);
  digitalWrite(dir_pin, LOW);
}

void stepAll(int speed) {
  digitalWrite(step_pin, HIGH);
  delayMicroseconds(speed);
  digitalWrite(step_pin, LOW);
  delayMicroseconds(speed);
}

void loop() {
  if(digitalRead(A0) == LOW) {  
    stepAll(steptime);
  }
}
