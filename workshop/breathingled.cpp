// C++ code
//
int x=0,a=1;
void setup()
{
  pinMode(3, OUTPUT);
}

void loop()
{
  analogWrite(3,x);
  x=x+a;
  if(x==255) a=-1;
  if(x==0) a=1;
  delay(5);
}
