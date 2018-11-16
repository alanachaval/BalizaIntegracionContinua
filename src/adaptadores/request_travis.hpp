#ifndef BALIZAINTEGRACIONCONTINUA_ADAPTADORES_REQUEST_TRAVIS_H_
#define BALIZAINTEGRACIONCONTINUA_ADAPTADORES_REQUEST_TRAVIS_H_

#include "../dominio/estado_del_build.hpp"
#include "request.hpp"
#include <string>

namespace adaptadores
{

using namespace dominio;
using namespace adaptadores;

class RequestTravis : public Request
{
public:
  RequestTravis(std::string url, std::string repositorio, std::string token);
  virtual EstadoDelBuild ObtenerEstado();
  ~RequestTravis();

private:
  std::string url_;
  std::string repositorio_;
  std::string token_;
  int fallos;
  EstadoDelBuild estado;
  bool QuedarseConResultado(const char **payload);
  EstadoDelBuild DecidirEstado(const char *nombreDeEstado);
};

} // namespace adaptadores

#endif // BALIZAINTEGRACIONCONTINUA_ADAPTADORES_REQUEST_TRAVIS_H_