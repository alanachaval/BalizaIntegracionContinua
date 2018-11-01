#ifndef BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CONTROLADOR_LED_ROJO_VERDE_H_
#define BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CONTROLADOR_LED_ROJO_VERDE_H_

#include "controlador_led.hpp"

namespace adaptadores
{

using namespace adaptadores;

class ControladorLedRojoVerde : public ControladorLed
{
  public:
    ControladorLedRojoVerde();
    virtual void PrenderLedRojo();
    virtual void ApagarLedRojo();
    virtual void PrenderLedVerde();
    virtual void ApagarLedVerde();
};

} // namespace adaptadores

#endif // BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CONTROLADOR_LED_ROJO_VERDE_H_