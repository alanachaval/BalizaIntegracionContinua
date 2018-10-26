#ifndef BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CONTROLADOR_LED_BUILT_IN_H_
#define BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CONTROLADOR_LED_BUILT_IN_H_

#include "controlador_led.hpp"

namespace adaptadores
{

using namespace adaptadores;

class ControladorLedBuiltIn : public ControladorLed
{
  public:
    ControladorLedBuiltIn();
    virtual void PrenderLedRojo();
    virtual void ApagarLedRojo();
    virtual void PrenderLedVerde();
    virtual void ApagarLedVerde();
};

} // namespace adaptadores

#endif // BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CONTROLADOR_LED_BUILT_IN_H_