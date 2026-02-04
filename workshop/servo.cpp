//pin 11 is servo signal
#include <Servo.h>
Servo rotate;
void setup()
{
  pinMode(11,OUTPUT);
  rotate.attach(11);
  rotate.write(0);
  delay(1000);
  rotate.write(180);
  delay(2000);
  rotate.write(0);
}

void loop()
{
 
}
