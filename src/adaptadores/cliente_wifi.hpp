#ifndef BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CLIENTE_WIFI_H_
#define BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CLIENTE_WIFI_H_

#include "../dominio/estado_del_build.hpp"

namespace adaptadores
{

class ClienteWiFi
{
public:
  virtual bool Conectar(const char *ssid, const char *password);
  virtual bool EstaConectado();
};

} // namespace adaptadores

#endif // BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CLIENTE_WIFI_H_