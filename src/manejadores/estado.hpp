#ifndef BALIZAINTEGRACIONCONTINUA_MANEJADORES_ESTADO_H_
#define BALIZAINTEGRACIONCONTINUA_MANEJADORES_ESTADO_H_

#include <string>
#include <map>
#include "manejador.hpp"
#include "../adaptadores/cliente_wifi.hpp"
#include "../dominio/estado_del_build.hpp"
#include "../dominio/procesador.hpp"

namespace manejadores
{

class Estado : public Manejador
{
public:
  Estado(dominio::Procesador *procesador, adaptadores::ClienteWiFi *cliente_wifi);
  virtual std::string Responder(std::map<std::string, std::string> datos);

private:
  dominio::Procesador *procesador_;
  adaptadores::ClienteWiFi *cliente_wifi_;
};

} // namespace manejadores

#endif // BALIZAINTEGRACIONCONTINUA_MANEJADORES_ESTADO_H_