#ifndef BALIZAINTEGRACIONCONTINUA_ADAPTADORES_SERVIDOR_WIFI_H_
#define BALIZAINTEGRACIONCONTINUA_ADAPTADORES_SERVIDOR_WIFI_H_

#include "../dominio/estado_del_build.hpp"

namespace adaptadores
{

class ServidorWiFi
{
public:
  virtual void Iniciar(const char *ssid, const char *password);
  virtual const char* ObtenerIP();
  virtual void AtenderCliente();
};

} // namespace adaptadores

#endif // BALIZAINTEGRACIONCONTINUA_ADAPTADORES_SERVIDOR_WIFI_H_