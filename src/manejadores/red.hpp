#ifndef BALIZAINTEGRACIONCONTINUA_MANEJADORES_RED_H_
#define BALIZAINTEGRACIONCONTINUA_MANEJADORES_RED_H_

#include <string>
#include <map>
#include "manejador.hpp"
#include "../adaptadores/cliente_wifi.hpp"

namespace manejadores
{

using namespace adaptadores;

class Red : public Manejador
{
public:
  Red(ClienteWiFi *cliente_wifi);
  virtual std::string Responder(std::map<std::string, std::string> datos);

private:
  ClienteWiFi *cliente_wifi_;
};

} // namespace manejadores

#endif // BALIZAINTEGRACIONCONTINUA_MANEJADORES_RED_H_