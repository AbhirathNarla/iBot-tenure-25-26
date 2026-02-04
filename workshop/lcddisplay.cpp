//https://www.tinkercad.com/things/bNjexlkcio5-lcddisplay

#include <LiquidCrystal.h>
LiquidCrystal lcd(2,4,9,10,11,12);
//RS  E  D4  D5  D6  D7
void setup(){
  lcd.begin(16,2);
lcd.setCursor(0, 0);
  lcd.print("Hello World");
lcd.setCursor(0,1);
lcd.print("ABHIRATH");
}
void loop(){
}
