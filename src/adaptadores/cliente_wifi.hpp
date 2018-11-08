#ifndef BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CLIENTE_WIFI_H_
#define BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CLIENTE_WIFI_H_

#include "../dominio/estado_del_build.hpp"
#include <string>

namespace adaptadores
{

class ClienteWiFi
{
public:
  ClienteWiFi();
  virtual bool Conectar(std::string ssid, std::string password);
  virtual bool EstaConectado();
  virtual bool Reconectar();

private:
  std::string ssid_;
  std::string password_;
  int intentos_;
};

} // namespace adaptadores

#endif // BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CLIENTE_WIFI_H_