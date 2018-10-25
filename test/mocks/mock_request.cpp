#include "gmock/gmock.h"
#include "request.hpp"

using namespace dominio;

class MockRequest : public Request
{
public:
  MOCK_METHOD0(ObtenerEstado, EstadoDelBuild());
};