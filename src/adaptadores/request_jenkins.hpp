#ifndef BALIZAINTEGRACIONCONTINUA_ADAPTADORES_REQUEST_JENKINS_H_
#define BALIZAINTEGRACIONCONTINUA_ADAPTADORES_REQUEST_JENKINS_H_

#include "../dominio/estado_del_build.hpp"
#include "request.hpp"
#include <string>

namespace adaptadores
{

using namespace dominio;
using namespace adaptadores;

class RequestJenkins : public Request
{
public:
  RequestJenkins(std::string url, std::string repositorio, std::string usuario, std::string token);
  virtual EstadoDelBuild ObtenerEstado();
  ~RequestJenkins();

private:
  std::string url_;
  std::string repositorio_;
  std::string base64_usuario_token_;
  int fallos;
  EstadoDelBuild estado;
  bool QuedarseConResultado(const char **payload);
  EstadoDelBuild DecidirEstado(const char *nombreDeEstado);
  std::string base64_encode(unsigned char const *bytes_to_encode, unsigned int in_len);
};

} // namespace adaptadores

#endif // BALIZAINTEGRACIONCONTINUA_ADAPTADORES_REQUEST_JENKINS_H_