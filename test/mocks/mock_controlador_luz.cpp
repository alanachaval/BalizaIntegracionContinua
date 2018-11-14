#include "adaptadores/controlador_led.hpp"

using namespace adaptadores;

class MockControladorLuz : public ControladorLuz
{
public:
  MockControladorLuz()
  {
    luz_roja_encendida_ = false;
    luz_verde_encendida_ = false;
    luz_amarilla_encendida_ = true;
  }

  void PrenderLuzRoja()
  {
    luz_roja_encendida_ = true;
  }

  void ApagarLuzRoja()
  {
    luz_roja_encendida_ = false;
  }

  void PrenderLuzVerde()
  {
    luz_verde_encendida_ = true;
  }

  void ApagarLuzVerde()
  {
    luz_verde_encendida_ = false;
  }

  void PrenderLuzAmarilla()
  {
    luz_amarilla_encendida_ = true;
  }

  void ApagarLuzAmarilla()
  {
    luz_amarilla_encendida_ = false;
  }

  bool LuzRojaEncendida()
  {
    return luz_roja_encendida_;
  }

  bool LuzVerdeEncendida()
  {
    return luz_verde_encendida_;
  }

  bool LuzAmarillaEncendida()
  {
    return luz_amarilla_encendida_;
  }

private:
  bool luz_roja_encendida_;
  bool luz_verde_encendida_;
  bool luz_amarilla_encendida_;
};