#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "adaptadores/request.hpp"
#include "adaptadores/controlador_luz.hpp"
#include "mocks/mock_request.cpp"
#include "mocks/mock_controlador_luz.cpp"
#include "dominio/procesador.hpp"
#include "dominio/visualizador_de_estado.hpp"

using namespace dominio;
using ::testing::AtLeast;
using ::testing::Return;

TEST(Procesador, obtiene_estado_desconectado_y_lo_asigna)
{
    Procesador *procesador = new Procesador();
    MockRequest *mock_request = new MockRequest();
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();
    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);
    procesador->SetRequest(mock_request);
    procesador->SetVisualizadorDeEstado(visualizador_de_estado);
    EXPECT_CALL(*mock_request, ObtenerEstado()).WillOnce(Return(kEstadoDesconectado));

    procesador->ActualizarEstado();

    EXPECT_TRUE(mock_controlador_luz->LuzVerdeEncendida());
    EXPECT_TRUE(mock_controlador_luz->LuzRojaEncendida());

    delete procesador;
    delete mock_request;
    delete visualizador_de_estado;
    delete mock_controlador_luz;
}

TEST(Procesador, obtiene_estado_correcto_y_lo_asigna)
{
    Procesador *procesador = new Procesador();
    MockRequest *mock_request = new MockRequest();
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();
    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);
    procesador->SetRequest(mock_request);
    procesador->SetVisualizadorDeEstado(visualizador_de_estado);
    EXPECT_CALL(*mock_request, ObtenerEstado()).WillOnce(Return(kEstadoCorrecto));

    procesador->ActualizarEstado();

    EXPECT_TRUE(mock_controlador_luz->LuzVerdeEncendida());
    EXPECT_FALSE(mock_controlador_luz->LuzRojaEncendida());

    delete procesador;
    delete mock_request;
    delete visualizador_de_estado;
    delete mock_controlador_luz;
}

TEST(Procesador, obtiene_estado_incorrecto_y_lo_asigna)
{
    Procesador *procesador = new Procesador();
    MockRequest *mock_request = new MockRequest();
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();
    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);
    procesador->SetRequest(mock_request);
    procesador->SetVisualizadorDeEstado(visualizador_de_estado);
    EXPECT_CALL(*mock_request, ObtenerEstado()).WillOnce(Return(kEstadoIncorrecto));

    procesador->ActualizarEstado();

    EXPECT_TRUE(mock_controlador_luz->LuzRojaEncendida());
    EXPECT_FALSE(mock_controlador_luz->LuzVerdeEncendida());

    delete procesador;
    delete mock_request;
    delete visualizador_de_estado;
    delete mock_controlador_luz;
}
