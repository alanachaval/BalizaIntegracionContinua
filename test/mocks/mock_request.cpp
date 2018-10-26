#include "gmock/gmock.h"
#include "adaptadores/request.hpp"

using namespace adaptadores;

class MockRequest : public Request
{
public:
  MOCK_METHOD0(ObtenerEstado, EstadoDelBuild());
};