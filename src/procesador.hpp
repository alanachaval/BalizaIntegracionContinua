#ifndef BALIZAINTEGRACIONCONTINUA_PROCESADOR_H_
#define BALIZAINTEGRACIONCONTINUA_PROCESADOR_H_

#include "request.hpp"
#include "visualizador_de_estado.hpp"

namespace dominio
{

using namespace dominio;

class Procesador
{
public:
  EstadoDelBuild ObtenerEstado();
  void SetRequest(Request *request);
  void SetVisualizadorDeEstado(VisualizadorDeEstado *);
  void ActualizarEstado();

private:
  Request *request_;
};

} // namespace dominio

#endif // BALIZAINTEGRACIONCONTINUA_PROCESADOR_H_