#ifndef BALIZAINTEGRACIONCONTINUA_PROCESADOR_H_
#define BALIZAINTEGRACIONCONTINUA_PROCESADOR_H_

#include "estados.hpp"

namespace dominio
{

class Procesador
{
public:
  dominio::Estados ObtenerEstado();
};

} // namespace dominio

#endif // BALIZAINTEGRACIONCONTINUA_PROCESADOR_H_