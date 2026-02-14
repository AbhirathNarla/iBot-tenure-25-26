#include <Arduino.h>

const int buzzer = 11;
const int led = 12;
const int ldr1 = 8; //bottom one
const int ldr2 = 7; //top one
const int button = 2;
int mode = 0;
void setup() {
  Serial.begin(115200);

  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT); 
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(button, INPUT_PULLUP);

}
int f = 1200;
bool ascending = true;
void loop() {
  if(f == 2400) ascending = false;
  if(f == 1200) ascending = true;
  if(ascending){
    f += 5;
  }
  else{
    f -= 5;
  }
  if(digitalRead(ldr1) == LOW && digitalRead(ldr2) == HIGH){  
    mode = 1;
  }
  if(digitalRead(button) == LOW){
    mode = 0;
  }
  if(mode == 1){
    // Ambulance sound
    // digitalWrite(led, HIGH);
    tone(buzzer, f);
    delay(5);
    // digitalWrite(led, LOW);  
  }
  else if(mode == 0){
    noTone(buzzer);
    digitalWrite(led, LOW);
  } 
}

