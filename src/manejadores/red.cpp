#include "red.hpp"
#include "../adaptadores/cliente_wifi.hpp"

using namespace manejadores;

Red::Red(ClienteWiFi *cliente_wifi)
{
    cliente_wifi_ = cliente_wifi;
}

std::string Red::Responder(std::map<std::string, std::string> *datos)
{
    std::map<std::string, std::string>::iterator ssid = datos->find("red_wifi");
    if (ssid == datos->end())
    {
        return "Error : sin parametro red_wifi";
    }
    std::map<std::string, std::string>::iterator password = datos->find("clave_red_wifi");
    if (password == datos->end())
    {
        return "Error : sin parametro clave_red_wifi";
    }
    cliente_wifi_->Conectar(ssid->second, password->second);
    return "OK";
}