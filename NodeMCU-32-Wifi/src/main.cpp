#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "ArduinoJson.h"

const char* ssid = "AndroidAP";     // <-- You should set this
const char* password =  "ninjanet"; // <-- You should set this

HTTPClient http;
StaticJsonDocument<1024> data;

void setup() {
  Serial.begin(115200);
  delay(1000);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
}

void loop() {
  // Url to get data: http://movia-oi-x.azurewebsites.net/api/stop/{stopPointId}
  // A couple of nearby stop points:
  // 471 - Elektrovej (Lundtoftevej), North bound
  // 499 - Elektrovej (Lundtoftevej), South bound
  // 6026 - Rævehøjvej, DTU (Helsingørmotorvejen), North bound
  // 6015 - Rævehøjvej, DTU (Helsingørmotorvejen), South bound  
  http.begin("http://movia-oi-x.azurewebsites.net/api/stop/499");  // <-- You can change StopPointId here
  int httpCode = http.GET();  
  
  //Check for the returning code
  if (httpCode != 200) { 
    Serial.println("Error on HTTP request");
    http.end();
    return;
  }

  String payload = http.getString();
  http.end();

  // Parse JSON
  auto error = deserializeJson(data, payload);

  if (error) {
      Serial.print(F("deserializeJson() failed with code "));
      Serial.println(error.c_str());
      return;
  }

  const char* time = data["time"];
  Serial.printf("Time: %s\n", time);
  
  JsonArray departures = data["departures"].as<JsonArray>();
  Serial.printf("%d departures\n", departures.size());
  for (JsonVariant departure : departures) {
      const char* line = departure["line"];
      const char* destination = departure["destination"];
      //const char* depatureTime = departure["depatureTime"];
      int depatureInMinutes = departure["depatureInMinutes"];
      Serial.printf("%s mod %s: %d min\n", line, destination, depatureInMinutes);
  }

  Serial.println();

  delay(10000);
}
