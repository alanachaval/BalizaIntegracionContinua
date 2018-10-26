#ifndef BALIZAINTEGRACIONCONTINUA_ADAPTADORES_WIFI_H_
#define BALIZAINTEGRACIONCONTINUA_ADAPTADORES_WIFI_H_

#include "../dominio/estado_del_build.hpp"

namespace adaptadores
{

class Wifi
{
  public:
    virtual bool conectar(const char *ssid, const char *password);
    virtual bool estaConectado();
};

} // namespace adaptadores

#endif // BALIZAINTEGRACIONCONTINUA_ADAPTADORES_WIFI_H_