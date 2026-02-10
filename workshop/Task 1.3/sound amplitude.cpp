#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

int analogpin = A1; // Analog pin for sound sensor input
Adafruit_SSD1306 display(128, 64, &Wire, -1);


void setup() {
  pinMode(analogpin, INPUT); 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  int soundlevel = analogRead(analogpin); 
  int amplitude = map(soundlevel, 0, 1023, 0, 64);
  int time = millis();
  int lastframe = 0;
  if (time - lastframe > 50){ 
    display.clearDisplay();
    display.fillRoundRect(62,0, 4, amplitude, 0, SSD1306_WHITE);
    display.display();
    lastframe = time;
  }
}

