#include "red.hpp"
#include "../adaptadores/cliente_wifi.hpp"

using namespace manejadores;

Red::Red(ClienteWiFi *cliente_wifi)
{
    cliente_wifi_ = cliente_wifi;
}

std::string Red::Responder(std::map<std::string, std::string> datos)
{
    return "";
}