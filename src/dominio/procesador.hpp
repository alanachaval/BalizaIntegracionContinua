#ifndef BALIZAINTEGRACIONCONTINUA_DOMINIO_PROCESADOR_H_
#define BALIZAINTEGRACIONCONTINUA_DOMINIO_PROCESADOR_H_

#include "../adaptadores/request.hpp"
#include "visualizador_de_estado.hpp"

namespace dominio
{

using namespace dominio;

class Procesador
{
public:
  Procesador();
  void SetRequest(Request *request);
  void SetVisualizadorDeEstado(VisualizadorDeEstado *visualizador_de_estado);
  EstadoDelBuild GetEstado();
  void ActualizarEstado();

private:
  Request *request_;
  VisualizadorDeEstado *visualizador_de_estado_;
  EstadoDelBuild estado_del_build_;
};

} // namespace dominio

#endif // BALIZAINTEGRACIONCONTINUA_DOMINIO_PROCESADOR_H_