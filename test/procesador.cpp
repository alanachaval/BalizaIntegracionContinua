#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "procesador.hpp"
#include "request.hpp"
#include "visualizador_de_estado.hpp"
#include "controlador_led.hpp"
#include "mocks/mock_request.cpp"
#include "mocks/mock_controlador_led.cpp"

//VER PORQUE ES NESESARIO
#include "visualizador_de_estado.cpp"

using namespace dominio;
using ::testing::AtLeast;
using ::testing::Return;

TEST(VisualizadorDeEstado, inicializa_en_estado_desconocido)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *controlador_de_led = new MockControladorLed();
    EXPECT_CALL(*controlador_de_led, PrenderLedRojo())
        .Times(1);
    EXPECT_CALL(*controlador_de_led, PrenderLedVerde())
        .Times(1);
    visualizador_de_estado->SetControladorLed(controlador_de_led);

    visualizador_de_estado->Actualizar(1);

    delete visualizador_de_estado;
    delete controlador_de_led;
}

TEST(Procesador, inicializa_en_estado_desconocido)
{
    Procesador *procesador = new Procesador();
    MockRequest *request = new MockRequest();
    EXPECT_CALL(*request, ObtenerEstado())
        .Times(AtLeast(1))
        .WillOnce(Return(kEstadoDesconocido));
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *controlador_de_led = new MockControladorLed();
    EXPECT_CALL(*controlador_de_led, PrenderLedRojo())
        .Times(AtLeast(1));

    visualizador_de_estado->SetControladorLed(controlador_de_led);
    procesador->SetRequest(request);

    delete procesador;
    delete request;
    delete visualizador_de_estado;
    delete controlador_de_led;
}

TEST(Procesador, obtiene_estado_correcto_lo_asigna)
{
    Procesador *procesador = new Procesador();
    MockRequest *request = new MockRequest();
    EXPECT_CALL(*request, ObtenerEstado())
        .Times(AtLeast(1))
        .WillOnce(Return(kEstadoCorrecto));
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *controlador_de_led = new MockControladorLed();
    EXPECT_CALL(*controlador_de_led, PrenderLedVerde())
        .Times(1);
    visualizador_de_estado->SetControladorLed(controlador_de_led);

    procesador->SetRequest(request);
    procesador->SetVisualizadorDeEstado(visualizador_de_estado);
    procesador->ActualizarEstado();

    delete procesador;
    delete request;
    delete visualizador_de_estado;
}
