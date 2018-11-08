#ifndef BALIZAINTEGRACIONCONTINUA_ADAPTADORES_REQUEST_H_
#define BALIZAINTEGRACIONCONTINUA_ADAPTADORES_REQUEST_H_

#include "../dominio/estado_del_build.hpp"

namespace adaptadores
{

using namespace dominio;

class Request
{
public:
  virtual EstadoDelBuild ObtenerEstado() = 0;
  virtual ~Request(){};
};

} // namespace adaptadores

#endif // BALIZAINTEGRACIONCONTINUA_ADAPTADORES_REQUEST_H_