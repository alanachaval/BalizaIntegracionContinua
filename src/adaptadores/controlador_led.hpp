#ifndef BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CONTROLADOR_LED_H_
#define BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CONTROLADOR_LED_H_

namespace adaptadores
{

class ControladorLed
{
public:
  virtual void PrenderLedRojo() = 0;
  virtual void ApagarLedRojo() = 0;
  virtual void PrenderLedVerde() = 0;
  virtual void ApagarLedVerde() = 0;
};

} // namespace adaptadores

#endif // BALIZAINTEGRACIONCONTINUA_ADAPTADORES_CONTROLADOR_LED_H_