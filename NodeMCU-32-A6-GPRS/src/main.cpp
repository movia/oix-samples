#include <Arduino.h>
#include "ArduinoJson.h"

StaticJsonDocument<1024> data;

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    Serial2.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(Serial2.available()) 
  {
    Serial.write(Serial2.read());//Forward what Software Serial received to Serial Port
  }
}

void setup() {
  Serial.begin(9600);


  Serial2.begin(115200);
  delay(1000);

  Serial.println("Here!");
  Serial2.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  Serial2.println("AT+CSQ"); //Signal quality test, value range is 0-31 , 31 is the best
  updateSerial();
  Serial2.println("AT+CCID"); //Read SIM information to confirm whether the SIM is plugged
  updateSerial();
  Serial2.println("AT+CREG?"); //Check whether it has registered in the network
  updateSerial();
}

void loop()
{
  updateSerial();
}
