#ifndef BALIZAINTEGRACIONCONTINUA_MANEJADORES_INDEX_H_
#define BALIZAINTEGRACIONCONTINUA_MANEJADORES_INDEX_H_

#include <string>
#include <map>
#include "manejador.hpp"

namespace manejadores
{

class Index : public Manejador
{
public:
  virtual std::string Responder(std::map<std::string, std::string> *datos);
};

} // namespace manejadores

#endif // BALIZAINTEGRACIONCONTINUA_MANEJADORES_INDEX_H_