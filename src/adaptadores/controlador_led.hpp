#ifndef BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CONTROLADOR_LED_H_
#define BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CONTROLADOR_LED_H_

#include "controlador_luz.hpp"

namespace adaptadores
{

using namespace adaptadores;

class ControladorLed : public ControladorLuz
{
public:
  ControladorLed();
  virtual void PrenderLuzRoja();
  virtual void ApagarLuzRoja();
  virtual void PrenderLuzVerde();
  virtual void ApagarLuzVerde();
  virtual void PrenderLuzAmarilla();
  virtual void ApagarLuzAmarilla();
};

} // namespace adaptadores

#endif // BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CONTROLADOR_LED_H_