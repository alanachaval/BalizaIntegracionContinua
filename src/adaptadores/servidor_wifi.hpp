#ifndef BALIZAINTEGRACIONCONTINUA_ADAPTADORES_SERVIDOR_WIFI_H_
#define BALIZAINTEGRACIONCONTINUA_ADAPTADORES_SERVIDOR_WIFI_H_

#include "../manejadores/manejador.hpp"
#include "cliente_wifi.hpp"
#include "../dominio/estado_del_build.hpp"
#include "../dominio/procesador.hpp"
#include <map>

namespace adaptadores
{

class ServidorWiFi
{
public:
  ServidorWiFi(Procesador *procesador, ClienteWiFi *cliente_wifi);
  virtual void Iniciar(const char *ssid, const char *password);
  virtual const char *ObtenerIP();
  virtual void AtenderCliente();

private:
  std::map<std::string, manejadores::Manejador *> manejadores_;
};

} // namespace adaptadores

#endif // BALIZAINTEGRACIONCONTINUA_ADAPTADORES_SERVIDOR_WIFI_H_