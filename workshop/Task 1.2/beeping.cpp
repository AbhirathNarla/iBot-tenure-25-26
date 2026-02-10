// C++ code
//pin 6 is buzzer
void setup()
{
  pinMode(6, OUTPUT);
}

void loop()
{
  tone(6,2000);
  delay(1000);
  noTone(6);
  delay(1000);
}
