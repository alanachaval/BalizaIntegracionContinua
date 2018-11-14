#ifndef BALIZAINTEGRACIONCONTINUA_DOMINIO_VISUALIZADOR_DE_ESTADO_H_
#define BALIZAINTEGRACIONCONTINUA_DOMINIO_VISUALIZADOR_DE_ESTADO_H_

#include "../adaptadores/controlador_luz.hpp"
#include "estado_del_build.hpp"

namespace dominio
{

using namespace dominio;
using namespace adaptadores;

class VisualizadorDeEstado
{
public:
  void SetControladorLuz(ControladorLuz *controlador_luz);
  void SetEstadoDelBuild(EstadoDelBuild estado_del_build);
  void Actualizar(unsigned long milisegundos);
  static const unsigned long kTiempoDeCadaParpadeo = 1000UL;
  static const unsigned long kParpadeosDeLuz = 5UL;

private:
  ControladorLuz *controlador_luz_;
  EstadoDelBuild estado_actual_;
  EstadoDelBuild estado_anterior_;
  unsigned long tiempo_de_parpadeos_;
  unsigned long tiempo_desde_ultimo_cambio_;
  bool animacion_en_ejecucion_;
  void (VisualizadorDeEstado::*actualizar_actual_)(bool);
  void ActualizarEstadoCorrecto(bool led_encendido);
  void ActualizarEstadoIncorrecto(bool led_encendido);
  void ActualizarEstadoDesconectado(bool led_encendido);
  void ActualizarEstadoEjecutando(bool led_encendido);
};

} // namespace dominio

#endif // BALIZAINTEGRACIONCONTINUA_DOMINIO_VISUALIZADOR_DE_ESTADO_H_