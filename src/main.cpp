#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "ssid";
const char* password = "password";
 
void setup() {
  Serial.begin(115200);
  delay(4000);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
}
 
void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("https://api.travis-ci.com/builds?limit=1");
    http.addHeader("Travis-API-Version", "3", false, false);
    http.addHeader("Authorization", "token 701nbQJWHx2jErKGZ_jPxg", false, false);
    int httpCode = http.GET();
 
    if (httpCode > 0) {
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
    
    } else {
      Serial.println("Error on HTTP request");
    }
 
    http.end();
  }
 
  delay(10000);
}