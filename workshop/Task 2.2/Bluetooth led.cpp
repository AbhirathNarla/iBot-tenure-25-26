#include <Arduino.h>
#include <BluetoothSerial.h>
BluetoothSerial SerialBT;

void setup(){
    pinMode(2, OUTPUT);
    Serial.begin(115200);
    SerialBT.begin("ESP32_Abhirath"); // Bluetooth device name
    Serial.print("Connecting");
    while (!SerialBT.connected())
    {
        Serial.print(".");
        delay(500);
    }
    Serial.println("Connected to Bluetooth");
}

void loop(){
    if(SerialBT.available()){
        char val = SerialBT.read();
        if (val == '1') {
            digitalWrite(2, HIGH); 
            Serial.println("LED ON");
        } 
        else if (val == '0') {
            digitalWrite(2, LOW); 
            Serial.println("LED OFF");
        }
    }
    
}
