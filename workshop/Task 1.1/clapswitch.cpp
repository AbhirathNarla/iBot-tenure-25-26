//2 is DO of sound sensor

void setup() {
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);  
}

void loop() {
  if (digitalRead(2) == HIGH) {
    digitalWrite(13, HIGH); 
    delay(2000);
    digitalWrite(13,LOW);
    delay(2000);
}
}
