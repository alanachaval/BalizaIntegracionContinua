#ifndef BALIZAINTEGRACIONCONTINUA_VISUALIZADOR_DE_ESTADO_H_
#define BALIZAINTEGRACIONCONTINUA_VISUALIZADOR_DE_ESTADO_H_

#include "controlador_led.hpp"

namespace dominio
{

using namespace dominio;

class VisualizadorDeEstado
{
public:
  void SetControladorLed(ControladorLed *controlador_led);
  void Actualizar(int milisegundos);

private:
  ControladorLed *controlador_led_;
};

} // namespace dominio

#endif // BALIZAINTEGRACIONCONTINUA_VISUALIZADOR_DE_ESTADO_H_