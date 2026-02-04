#include <DHT.h>
const int DHT_pin = 6;
DHT dht(DHT_pin,DHT11);

float Humidity, Temperature; 

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  Humidity = dht.readHumidity();
  Temperature = dht.readTemperature();
  if(isnan(Humidity) || isnan(Temperature))
  {
    Serial.println("Reading Failed");
  }
  else{
    Serial.print("Temperature: ");
    Serial.println(Temperature);
    Serial.print("Humidity %: ");
    Serial.println(Humidity);
    
  }
      delay(2000);
}
