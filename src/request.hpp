#ifndef BALIZAINTEGRACIONCONTINUA_REQUEST_H_
#define BALIZAINTEGRACIONCONTINUA_REQUEST_H_

#include "estado_del_build.hpp"

namespace dominio
{

class Request
{
public:
  virtual EstadoDelBuild ObtenerEstado() = 0;
};

} // namespace dominio

#endif // BALIZAINTEGRACIONCONTINUA_REQUEST_H_