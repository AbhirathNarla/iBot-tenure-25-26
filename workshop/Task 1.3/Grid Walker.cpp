#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

const int up = 5;
const int down = 2;
const int right = 3;
const int left = 4;

const int Width = 128;
const int Height = 64;
const int Reset_Pin = -1;
Adafruit_SSD1306 display(Width, Height, &Wire, Reset_Pin);

struct input
{
  bool Right;
  bool Down;
  bool Up;
  bool Left;
};
struct input inputs;
int prev1x = 0,prev1y = 0;
int prev2x = 0,prev2y = 0;

class block{
public:
int x = 0, y = 0, s = 8, c= SSD1306_WHITE;
 block(int X = 0, int Y = 0, int S = 8, int C= SSD1306_WHITE){
  x = X;
  y = Y;
  s = S;
  c = C;
 }
 
 void update(input inputs){
 if(inputs.Right == true){

x += s;
 }
 else if(inputs.Left == true){
x -= s;
 }
 else if(inputs.Up == true){
y -= s;
 }
 else if(inputs.Down == true){
y += s;
 }
 if(x>=128) x = 0;
 else if(y>=64) y = 0;
 else if(x<0) x = 118;
 else if(y<0) y = 58;
 }
 void erase(int x1, int y1){
    display.fillRoundRect(x1,y1,s,s,0,SSD1306_BLACK);

  display.display();
 }
 void draw(){
    display.fillRoundRect(x,y,s,s,0,c);
  display.display();
 }

};
block Block;

void setup() {
  pinMode(right, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
  pinMode(up, INPUT_PULLUP);
  pinMode(left, INPUT_PULLUP);
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 Serial.begin(9600);
 Serial.println("Grid Walker");
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { 
    Serial.println("SSD1306 Allocation Failed");
  }

  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.println("Grid Walker");
  display.display();
  delay(2000);
  display.clearDisplay();
  display.fillRoundRect(Block.x,Block.y,Block.s,Block.s,0,Block.c);
  display.display();
}


void loop() {
inputs.Right = !digitalRead(right);
inputs.Left = !digitalRead(left);
inputs.Up = !digitalRead(up);
inputs.Down = !digitalRead(down);

Block.update(inputs);
if(prev1x!= Block.x ||  prev1y != Block.y ){
Block.erase(prev1x,prev1y);
prev1x = Block.x;
prev1y = Block.y;
}
if(prev2x != Block.x || prev2y != Block.y){
  Block.draw();
  prev2x = Block.x;
prev2y = Block.y;
}

}
