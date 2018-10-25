#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "procesador.hpp"
#include "request.hpp"
#include "visualizador_de_estado.hpp"
#include "mocks/mock_request.cpp"

using namespace dominio;
using ::testing::AtLeast;
using ::testing::Return;

TEST(Procesador, inicializa_en_estado_desconocido)
{
    Procesador *procesador = new Procesador();
    MockRequest* request = new MockRequest();
    EXPECT_CALL(*request, ObtenerEstado())
        .Times(AtLeast(1))
        .WillOnce(Return(kEstadoDesconocido));
    
    procesador->SetRequest(request);

    ASSERT_EQ(kEstadoDesconocido, procesador->ObtenerEstado());

    delete procesador;
    delete request;
}

TEST(Procesador, obtiene_estado_correcto_lo_asigna)
{
    Procesador *procesador = new Procesador();
    MockRequest* request = new MockRequest();
    EXPECT_CALL(*request, ObtenerEstado())
        .Times(AtLeast(1))
        .WillOnce(Return(kEstadoCorrecto));
    VisualizadorDeEstado* visualizador_de_estado = new VisualizadorDeEstado();

    procesador->SetRequest(request);
    procesador->SetVisualizadorDeEstado(visualizador_de_estado);
    procesador->ActualizarEstado();

    ASSERT_EQ(kEstadoCorrecto, procesador->ObtenerEstado());

    delete procesador;
    delete request;
    delete visualizador_de_estado;
}
