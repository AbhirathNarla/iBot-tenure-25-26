//https://www.tinkercad.com/things/efdBafdI3FI-ed25b002abhirathnarlai2ccommunication?sharecode=AZjqnRo071i2tTh64fKR3DJA-Ah7XFH4IeQJDsiXqlw
//Slave Arduino
#include <Wire.h>
volatile int y;
void receiveEvent(int howMany) {
if (Wire.available()) {
y = Wire.read(); 
}
}
void setup()
{
  pinMode(6,OUTPUT);
  Wire.begin(1);
  Serial.begin(9600);
  Wire.onReceive(receiveEvent);
  
}



void loop()
{

 analogWrite(6,y);
  delay(50);
  
} 

//Master Arduino
#include <Wire.h>
void setup()
{
Wire.begin();
  pinMode(A2,INPUT);
  Serial.begin(9600);
  
}

void loop()
{
 int x=analogRead(A2);
 int y = map(x,0,1023,0,255);
 Wire.beginTransmission(1);
  Wire.write(y);
  Wire.endTransmission();
  Serial.println(x);
  delay(50);
}
