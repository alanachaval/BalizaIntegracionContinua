#include "cliente_wifi.hpp"
#include <WiFi.h>
#include <Arduino.h>

using namespace adaptadores;

ClienteWiFi::ClienteWiFi()
{
    ssid_ = "";
    password_ = "";
    intentos_ = 0;
}

bool ClienteWiFi::Conectar(std::string ssid, std::string password)
{
    ssid_ = ssid;
    password_ = password;
    intentos_ = 0;
    WiFi.disconnect();
    return this->Reconectar();
}

bool ClienteWiFi::EstaConectado()
{
    return WiFi.status() == WL_CONNECTED;
}

bool ClienteWiFi::Reconectar()
{
    if (this->EstaConectado())
    {
        return true;
    }

    if (ssid_.length() == 0) //Evita iniciar el wifi antes de ser configurado
    {
        return false;
    }

    if (intentos_-- < 0)
    {
        Serial.print("ssid: ");
        Serial.println(ssid_.c_str());
        Serial.print("password: ");
        Serial.println(password_.c_str());
        WiFi.begin(ssid_.c_str(), password_.c_str());
        intentos_ = 15;
    }
    return false;
}