#ifndef BALIZAINTEGRACIONCONTINUA_MANEJADORES_REPOSITORIO_H_
#define BALIZAINTEGRACIONCONTINUA_MANEJADORES_REPOSITORIO_H_

#include <string>
#include <map>
#include "manejador.hpp"

namespace manejadores
{

class Repositorio : public Manejador
{
public:
  virtual std::string Responder(std::map<std::string, std::string> datos);
};

} // namespace manejadores

#endif // BALIZAINTEGRACIONCONTINUA_MANEJADORES_REPOSITORIO_H_