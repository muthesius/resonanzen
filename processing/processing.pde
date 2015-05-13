// Resonanzen v1.0

import processing.serial.*;
import cc.arduino.*;

Arduino arduino;

void setup () {
  println(Arduino.list());
  arduino = new Arduino(this, Arduino.list()[0], 57600);
  
  for (int i = 0; i <= 13; i++) {
    arduino.pinMode(i, Arduino.INPUT);
  }
  
  colorMode(HSB, width, 100, width);
  noStroke();
  background(0);

}

void draw() {
  rect(0,0,10,30);
  ellipse(10,20,40,50);

  int whichBar = mouseX / barWidth;
  if (whichBar != lastBar) {
    int barX = whichBar * barWidth;
    fill(barX, 100, mouseY);
    rect(barX, 0, barWidth, height);
    lastBar = whichBar;
  }
}
