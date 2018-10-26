#include <Arduino.h>
// Load Wi-Fi library
#include <WiFi.h>
#include "adaptadores/servidor_wifi.hpp"

using namespace adaptadores;

// Replace with your network credentials
const char* ssid     = "ESP32-Access-Point";
const char* password = "123456789";

ServidorWiFi* servidor_wifi;

void setup() {
  servidor_wifi = new ServidorWiFi();
  Serial.begin(115200);

  Serial.print("Setting AP (Access Point)…");
  servidor_wifi->Iniciar(ssid, password);

  Serial.print("AP IP address: ");
  Serial.println(servidor_wifi->ObtenerIP());
  
}

void loop(){
 servidor_wifi->AtenderCliente();
}