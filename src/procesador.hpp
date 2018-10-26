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
  void SetRequest(Request *request);
  void SetVisualizadorDeEstado(VisualizadorDeEstado *visualizador_de_estado);
  void ActualizarEstado();

private:
  Request *request_;
  VisualizadorDeEstado *visualizador_de_estado_;
};

} // namespace dominio

#endif // BALIZAINTEGRACIONCONTINUA_PROCESADOR_H_