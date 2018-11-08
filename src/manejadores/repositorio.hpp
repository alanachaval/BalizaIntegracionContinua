#ifndef BALIZAINTEGRACIONCONTINUA_MANEJADORES_REPOSITORIO_H_
#define BALIZAINTEGRACIONCONTINUA_MANEJADORES_REPOSITORIO_H_

#include <string>
#include <map>
#include "manejador.hpp"
#include "../dominio/procesador.hpp"

namespace manejadores
{

using namespace dominio;

class Repositorio : public Manejador
{
public:
  Repositorio(Procesador *procesador);
  virtual std::string Responder(std::map<std::string, std::string> datos);

private:
  Procesador *procesador_;
};

} // namespace manejadores

#endif // BALIZAINTEGRACIONCONTINUA_MANEJADORES_REPOSITORIO_H_