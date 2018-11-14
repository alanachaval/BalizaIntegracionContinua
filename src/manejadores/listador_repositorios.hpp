#ifndef BALIZAINTEGRACIONCONTINUA_MANEJADORES_LISTADOR_REPOSITORIOS_H_
#define BALIZAINTEGRACIONCONTINUA_MANEJADORES_LISTADOR_REPOSITORIOS_H_

#include <string>
#include <map>
#include "manejador.hpp"

namespace manejadores
{

class ListadorRepositorios : public Manejador
{
public:
  virtual std::string Responder(std::map<std::string, std::string> *datos);
};

} // namespace manejadores

#endif // BALIZAINTEGRACIONCONTINUA_MANEJADORES_LISTADOR_REPOSITORIOS_H_