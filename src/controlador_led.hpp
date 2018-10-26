#ifndef BALIZAINTEGRACIONCONTINUA_CONTROLADOR_LED_H_
#define BALIZAINTEGRACIONCONTINUA_CONTROLADOR_LED_H_

namespace dominio
{

class ControladorLed
{
public:
  virtual void PrenderLedRojo() = 0;
  virtual void ApagarLedRojo() = 0;
  virtual void PrenderLedVerde() = 0;
  virtual void ApagarLedVerde() = 0;
};

} // namespace dominio

#endif // BALIZAINTEGRACIONCONTINUA_CONTROLADOR_LED_H_