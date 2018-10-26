#ifndef BALIZAINTEGRACIONCONTINUA_ADAPTADORES_REQUEST_TRAVIS_H_
#define BALIZAINTEGRACIONCONTINUA_ADAPTADORES_REQUEST_TRAVIS_H_

#include "../dominio/estado_del_build.hpp"
#include "request.hpp"

namespace adaptadores
{

using namespace dominio;
using namespace adaptadores;

class RequestTravis : public Request
{
  public:
    virtual EstadoDelBuild ObtenerEstado();
};

} // namespace adaptadores

#endif // BALIZAINTEGRACIONCONTINUA_ADAPTADORES_REQUEST_TRAVIS_H_