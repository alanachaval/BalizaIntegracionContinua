#ifndef BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CONTROLADOR_LED_H_
#define BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CONTROLADOR_LED_H_

namespace adaptadores
{

class ControladorLed
{
public:
  ControladorLed();
  virtual void PrenderLedRojo();
  virtual void ApagarLedRojo();
  virtual void PrenderLedVerde();
  virtual void ApagarLedVerde();
};

} // namespace adaptadores

#endif // BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CONTROLADOR_LED_H_