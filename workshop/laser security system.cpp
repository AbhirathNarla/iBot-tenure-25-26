#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(2,4,9,10,11,12);
//RS  E  D4  D5  D6  D7

const int buzzer = 5;
const int lazer = 6;
const int ldr = 7;
int mode = 0;
int prevmode = 0;

void setup(){
  lcd.begin(16,2);
  pinMode(buzzer, OUTPUT);
  pinMode(lazer, OUTPUT);
  pinMode(ldr, INPUT);
  digitalWrite(lazer, HIGH);
}

void loop(){
  if(digitalRead(ldr) == HIGH){
    lcd.setCursor(0,0);
    lcd.print("Interference Detected");
    tone(buzzer, 1000);
    
    mode = 1;
  }
  else if(digitalRead(ldr) == LOW){
    lcd.setCursor(0,0);
    lcd.print("No Interference");
    noTone(buzzer);
    
    mode = 0;
  }
  if(mode == 1 && prevmode == 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Interference Detected");
    
  }
  else if(mode == 0 && prevmode == 1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("No Interference");
    
  }
  prevmode = mode;
}
