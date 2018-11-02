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
  unsigned long tiempo_desde_ultimo_cambio_;
  bool animacion_en_ejecucion_;
  bool (VisualizadorDeEstado::*actualizar_actual_)(unsigned long);
  static const unsigned long kTiempoDeCadaParpadeo = 500UL;
  static const unsigned long kParpadeosDelLed = 5UL;
  bool ActualizarEstadoCorrecto(unsigned long milisegundos);
  bool ActualizarEstadoIncorrecto(unsigned long milisegundos);
  bool ActualizarEstadoDesconectado(unsigned long milisegundos);
  bool ActualizarEstadoEjecutando(unsigned long milisegundos);
};

} // namespace dominio

#endif // BALIZAINTEGRACIONCONTINUA_DOMINIO_VISUALIZADOR_DE_ESTADO_H_