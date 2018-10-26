#include "gmock/gmock.h"
#include "controlador_led.hpp"

using namespace dominio;

class MockControladorLed : public ControladorLed
{
public:
  MOCK_METHOD0(PrenderLedRojo, void());
  MOCK_METHOD0(ApagarLedRojo, void());
  MOCK_METHOD0(PrenderLedVerde, void());
  MOCK_METHOD0(ApagarLedVerde, void());
};