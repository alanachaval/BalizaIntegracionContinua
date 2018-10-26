#include "wifi.hpp"
#include <WiFi.h>
#include <Arduino.h>

using namespace adaptadores;

bool Wifi::conectar(const char *ssid, const char *password)
{
    int intentos = 40;
    WiFi.begin(ssid, password);

    while (!this->estaConectado() && intentos > 0)
    {
        delay(1000);
        intentos--;
        Serial.println("Connecting to WiFi..");
    }

    if (this->estaConectado())
    {
        Serial.println("Connected to the WiFi network");
    }
    else
    {
        Serial.println("Not connected!");
    }

    return this->estaConectado();
}

bool Wifi::estaConectado()
{
    return WiFi.status() == WL_CONNECTED;
}