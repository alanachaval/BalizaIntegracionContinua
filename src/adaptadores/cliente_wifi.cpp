#include "cliente_wifi.hpp"
#include <WiFi.h>
#include <Arduino.h>

using namespace adaptadores;

bool ClienteWiFi::Conectar(const char *ssid, const char *password)
{
    int intentos = 0;
    WiFi.begin(ssid, password);

    while (!this->EstaConectado() && intentos > 0)
    {
        delay(1000);
        intentos--;
        Serial.println("Connecting to WiFi..");
    }

    if (this->EstaConectado())
    {
        Serial.println("Connected to the WiFi network");
    }
    else
    {
        Serial.println("Not connected!");
    }

    return this->EstaConectado();
}

bool ClienteWiFi::EstaConectado()
{
    return WiFi.status() == WL_CONNECTED;
}