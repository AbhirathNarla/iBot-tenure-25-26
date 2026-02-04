// C++ code
//pin 8 is signal pin of pir
int time = 0;
int previous = 0;
int prevstate = 1;
int i=0,j=0;
void setup()
{
  pinMode(8, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int currstate = digitalRead(8);
    
time = millis();
  if(currstate == 1&& j==i){
    previous = time;
    i++;
  }
  if(prevstate && currstate == 0){
    Serial.println(time - previous);
    j=i;
    
  }
  prevstate = currstate;
}
