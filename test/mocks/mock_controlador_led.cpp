#include "adaptadores/controlador_led.hpp"

using namespace adaptadores;

class MockControladorLed : public ControladorLed
{
public:
  MockControladorLed()
  {
    led_rojo_encendido_ = true;
    led_verde_encendido_ = true;
  }

  void PrenderLedRojo()
  {
    led_rojo_encendido_ = true;
  }

  void ApagarLedRojo()
  {
    led_rojo_encendido_ = false;
  }

  void PrenderLedVerde()
  {
    led_verde_encendido_ = true;
  }

  void ApagarLedVerde()
  {
    led_verde_encendido_ = false;
  }

  bool LedRojoEncendido()
  {
    return led_rojo_encendido_;
  }

  bool LedVerdeEncendido()
  {
    return led_verde_encendido_;
  }

private:
  bool led_rojo_encendido_;
  bool led_verde_encendido_;
};