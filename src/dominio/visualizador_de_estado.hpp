#ifndef BALIZAINTEGRACIONCONTINUA_DOMINIO_VISUALIZADOR_DE_ESTADO_H_
#define BALIZAINTEGRACIONCONTINUA_DOMINIO_VISUALIZADOR_DE_ESTADO_H_

#include "../adaptadores/controlador_led.hpp"
#include "estado_del_build.hpp"

namespace dominio
{

using namespace dominio;
using namespace adaptadores;

class VisualizadorDeEstado
{
public:
  void SetControladorLed(ControladorLed *controlador_led);
  void SetEstadoDelBuild(EstadoDelBuild estado_del_build);
  void Actualizar(unsigned long milisegundos);

private:
  ControladorLed *controlador_led_;
  EstadoDelBuild estado_actual_;
  EstadoDelBuild estado_anterior_;
  unsigned long tiempo_de_parpadeos_;
  static const unsigned long kTiempoDeCadaParpadeo = 500UL;
  static const unsigned long kParpadeosDelLed = 5UL;
};

} // namespace dominio

#endif // BALIZAINTEGRACIONCONTINUA_DOMINIO_VISUALIZADOR_DE_ESTADO_H_