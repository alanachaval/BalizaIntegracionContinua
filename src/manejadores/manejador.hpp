#ifndef BALIZAINTEGRACIONCONTINUA_MANEJADORES_MANEJADOR_H_
#define BALIZAINTEGRACIONCONTINUA_MANEJADORES_MANEJADOR_H_

#include <string>
#include <map>

namespace manejadores
{

class Manejador
{
public:
  virtual std::string Responder(std::map<std::string, std::string> *datos);
};

} // namespace manejadores

#endif // BALIZAINTEGRACIONCONTINUA_MANEJADORES_MANEJADOR_H_