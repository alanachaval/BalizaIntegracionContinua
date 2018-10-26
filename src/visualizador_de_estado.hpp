#ifndef BALIZAINTEGRACIONCONTINUA_VISUALIZADOR_DE_ESTADO_H_
#define BALIZAINTEGRACIONCONTINUA_VISUALIZADOR_DE_ESTADO_H_

#include "controlador_led.hpp"
#include "estado_del_build.hpp"

namespace dominio
{

using namespace dominio;

class VisualizadorDeEstado
{
public:
  void SetControladorLed(ControladorLed *controlador_led);
  void SetEstadoDelBuild(EstadoDelBuild estado_del_build);
  void Actualizar(int milisegundos);

private:
  ControladorLed *controlador_led_;
  EstadoDelBuild estado_del_build_;
};

} // namespace dominio

#endif // BALIZAINTEGRACIONCONTINUA_VISUALIZADOR_DE_ESTADO_H_