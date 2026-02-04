//pin 5 is trig and pin 6 is echo

int Distance, Duration;

void setup(){
  pinMode(5,OUTPUT);
  pinMode(6,INPUT);
	Serial.begin(9600);
}
void loop(){
  digitalWrite(5,LOW);
  delayMicroseconds(2);
  digitalWrite(5,HIGH);
  delayMicroseconds(10);
  digitalWrite(5,LOW);
  Duration = pulseIn(6,HIGH,40000);
  Distance = (Duration*0.343)/20;
  if(Duration ==0)Serial.println("No object found");
  else{
  Serial.print(Distance);
  Serial.println("cm");
  }
  delay(500);
}
