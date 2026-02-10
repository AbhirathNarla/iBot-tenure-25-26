#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <Adafruit_GFX.h>

const int Width = 128;
const int Height = 64;
const int LED_Pin = 2;
const int Reset_Pin = -1;
const int Time_Delay = 1000;
Adafruit_SSD1306 display(Width, Height, &Wire, Reset_Pin);

void setup() {
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { 
    Serial.println("SSD1306 Allocation Failed");
  }
}

void loop() {
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Hello World");
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setCursor(0,0);
  display.drawRect(10,10, 40, 20, SSD1306_WHITE);
  display.display();
  delay(2000);
}
