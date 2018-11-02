#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "adaptadores/request.hpp"
#include "adaptadores/controlador_led.hpp"
#include "mocks/mock_request.cpp"
#include "mocks/mock_controlador_led.cpp"
#include "dominio/procesador.hpp"
#include "dominio/visualizador_de_estado.hpp"

using namespace dominio;
using ::testing::AtLeast;
using ::testing::Return;

TEST(Procesador, obtiene_estado_desconocido_y_lo_asigna)
{
    Procesador *procesador = new Procesador();
    MockRequest *request = new MockRequest();
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *controlador_led = new MockControladorLed();

    visualizador_de_estado->SetControladorLed(controlador_led);
    procesador->SetRequest(request);
    procesador->SetVisualizadorDeEstado(visualizador_de_estado);
    
    EXPECT_CALL(*request, ObtenerEstado()).WillOnce(Return(kEstadoDesconocido));

    procesador->ActualizarEstado();

    EXPECT_TRUE(controlador_led->LedVerdeEncendido());
    EXPECT_TRUE(controlador_led->LedRojoEncendido());

    delete procesador;
    delete request;
    delete visualizador_de_estado;
    delete controlador_led;
}

TEST(Procesador, obtiene_estado_correcto_y_lo_asigna)
{
    Procesador *procesador = new Procesador();
    MockRequest *request = new MockRequest();
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *controlador_led = new MockControladorLed();

    visualizador_de_estado->SetControladorLed(controlador_led);
    procesador->SetRequest(request);
    procesador->SetVisualizadorDeEstado(visualizador_de_estado);

    EXPECT_CALL(*request, ObtenerEstado()).WillOnce(Return(kEstadoCorrecto));
  
    procesador->ActualizarEstado();

    EXPECT_TRUE(controlador_led->LedVerdeEncendido());
    EXPECT_FALSE(controlador_led->LedRojoEncendido());

    delete procesador;
    delete request;
    delete visualizador_de_estado;
    delete controlador_led;
}

TEST(Procesador, obtiene_estado_incorrecto_y_lo_asigna)
{
    Procesador *procesador = new Procesador();
    MockRequest *request = new MockRequest();
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *controlador_led = new MockControladorLed();

    visualizador_de_estado->SetControladorLed(controlador_led);
    procesador->SetRequest(request);
    procesador->SetVisualizadorDeEstado(visualizador_de_estado);

    EXPECT_CALL(*request, ObtenerEstado()).WillOnce(Return(kEstadoIncorrecto));
    
    procesador->ActualizarEstado();

    EXPECT_TRUE(controlador_led->LedRojoEncendido());
    EXPECT_FALSE(controlador_led->LedVerdeEncendido());

    delete procesador;
    delete request;
    delete visualizador_de_estado;
    delete controlador_led;
}
