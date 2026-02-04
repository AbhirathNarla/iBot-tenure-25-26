//https://www.tinkercad.com/things/2gesHyWxdpe-fake-communication?sharecode=undefined
// C++ code
//arduino 1
void setup()
{
  
  pinMode(A3, INPUT);
  pinMode(5,OUTPUT);
}

void loop()
{
  int x =analogRead(A3);
  int y= map(x,0,1023,0,255);
  analogWrite(5,y);
  delay(15);
}

//arduino 2

#include <Servo.h>
Servo rotate;
void setup()
{
  pinMode(A5,INPUT);
  rotate.attach(11);
}

void loop()
{
  int a= analogRead(A5);
  int b = map(a,0,1023,0,180);
  rotate.write(b);
  
}
