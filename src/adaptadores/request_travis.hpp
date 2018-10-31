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
  RequestTravis(const char *repositorio, const char *token);
  virtual EstadoDelBuild ObtenerEstado();

private:
  const char *repositorio_;
  const char *token_;
  int fallos;
  EstadoDelBuild estado;
  bool QuedarseConResultado(const char **payload);
  EstadoDelBuild DecidirEstado(const char* nombreDeEstado);
};

} // namespace adaptadores

#endif // BALIZAINTEGRACIONCONTINUA_ADAPTADORES_REQUEST_TRAVIS_H_