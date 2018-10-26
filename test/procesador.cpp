#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mocks/mock_request.cpp"
#include "mocks/mock_controlador_led.cpp"
#include "procesador.hpp"
#include "request.hpp"
#include "visualizador_de_estado.hpp"
#include "controlador_led.hpp"

using namespace dominio;
using ::testing::AtLeast;
using ::testing::Return;

TEST(VisualizadorDeEstado, inicializa_en_estado_desconocido)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *controlador_de_led = new MockControladorLed();

    visualizador_de_estado->SetControladorLed(controlador_de_led);

    EXPECT_CALL(*controlador_de_led, PrenderLedRojo()).Times(1);
    EXPECT_CALL(*controlador_de_led, PrenderLedVerde()).Times(1);

    visualizador_de_estado->Actualizar(1);

    delete visualizador_de_estado;
    delete controlador_de_led;
}

TEST(Procesador, obtiene_estado_desconocido_y_lo_asigna)
{
    Procesador *procesador = new Procesador();
    MockRequest *request = new MockRequest();
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *controlador_de_led = new MockControladorLed();

    visualizador_de_estado->SetControladorLed(controlador_de_led);
    procesador->SetRequest(request);
    procesador->SetVisualizadorDeEstado(visualizador_de_estado);
    
    EXPECT_CALL(*request, ObtenerEstado()).WillOnce(Return(kEstadoDesconocido));
    EXPECT_CALL(*controlador_de_led, PrenderLedRojo()).Times(1);
    EXPECT_CALL(*controlador_de_led, PrenderLedVerde()).Times(1);

    procesador->ActualizarEstado();
    visualizador_de_estado->Actualizar(1);

    delete procesador;
    delete request;
    delete visualizador_de_estado;
    delete controlador_de_led;
}

TEST(Procesador, obtiene_estado_correcto_y_lo_asigna)
{
    Procesador *procesador = new Procesador();
    MockRequest *request = new MockRequest();
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *controlador_de_led = new MockControladorLed();

    visualizador_de_estado->SetControladorLed(controlador_de_led);
    procesador->SetRequest(request);
    procesador->SetVisualizadorDeEstado(visualizador_de_estado);

    EXPECT_CALL(*request, ObtenerEstado()).WillOnce(Return(kEstadoCorrecto));
    EXPECT_CALL(*controlador_de_led, PrenderLedVerde()).Times(1);
    EXPECT_CALL(*controlador_de_led, ApagarLedRojo()).Times(1);

    procesador->ActualizarEstado();
    visualizador_de_estado->Actualizar(1);

    delete procesador;
    delete request;
    delete visualizador_de_estado;
    delete controlador_de_led;
}

TEST(Procesador, obtiene_estado_incorrecto_y_lo_asigna)
{
    Procesador *procesador = new Procesador();
    MockRequest *request = new MockRequest();
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *controlador_de_led = new MockControladorLed();

    visualizador_de_estado->SetControladorLed(controlador_de_led);
    procesador->SetRequest(request);
    procesador->SetVisualizadorDeEstado(visualizador_de_estado);

    EXPECT_CALL(*request, ObtenerEstado()).WillOnce(Return(kEstadoIncorrecto));
    EXPECT_CALL(*controlador_de_led, ApagarLedVerde()).Times(1);
    EXPECT_CALL(*controlador_de_led, PrenderLedRojo()).Times(1);

    procesador->ActualizarEstado();
    visualizador_de_estado->Actualizar(1);

    delete procesador;
    delete request;
    delete visualizador_de_estado;
    delete controlador_de_led;
}
