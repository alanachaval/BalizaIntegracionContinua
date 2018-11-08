#include "red.hpp"
#include "../adaptadores/cliente_wifi.hpp"

using namespace manejadores;

Red::Red(ClienteWiFi *cliente_wifi)
{
    cliente_wifi_ = cliente_wifi;
}

std::string Red::Responder(std::map<std::string, std::string> datos)
{
    const char *ssid = datos.find("red_wifi")->second.c_str();
    const char *password = datos.find("clave_red_wifi")->second.c_str();
    cliente_wifi_->Conectar(ssid, password);
    return "OK";
}