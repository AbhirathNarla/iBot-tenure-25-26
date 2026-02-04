//when we click the button the led should be turned on untill the next button press
//pin 4 is led, pin 6 is pushbutton

int prevstate = HIGH;
bool ledstate = false;

void setup()
{
  pinMode(4, OUTPUT);
  pinMode(6, INPUT_PULLUP);
}

void loop()
{
  int currstate = digitalRead(6);
 if (prevstate == HIGH && currstate == LOW){
    ledstate = !ledstate;
  }

  digitalWrite(4, ledstate);
 prevstate = currstate;
}
