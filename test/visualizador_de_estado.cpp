#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "adaptadores/controlador_led.hpp"
#include "mocks/mock_controlador_luz.cpp"
#include "dominio/visualizador_de_estado.hpp"

using namespace dominio;
using ::testing::AtLeast;
using ::testing::Return;

TEST(VisualizadorDeEstado, inicializa_en_estado_desconectado)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();

    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);

    EXPECT_TRUE(mock_controlador_luz->LuzRojaEncendida());
    EXPECT_TRUE(mock_controlador_luz->LuzVerdeEncendida());

    delete visualizador_de_estado;
    delete mock_controlador_luz;
}

TEST(VisualizadorDeEstado, encender_led_verde_al_cambiar_a_estado_correcto)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();
    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);

    visualizador_de_estado->SetEstadoDelBuild(kEstadoCorrecto);

    EXPECT_FALSE(mock_controlador_luz->LuzRojaEncendida());
    EXPECT_TRUE(mock_controlador_luz->LuzVerdeEncendida());

    delete visualizador_de_estado;
    delete mock_controlador_luz;
}

TEST(VisualizadorDeEstado, encender_led_rojo_al_cambiar_a_estado_incorrecto)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();
    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);

    visualizador_de_estado->SetEstadoDelBuild(kEstadoIncorrecto);

    EXPECT_FALSE(mock_controlador_luz->LuzVerdeEncendida());
    EXPECT_TRUE(mock_controlador_luz->LuzRojaEncendida());

    delete visualizador_de_estado;
    delete mock_controlador_luz;
}

TEST(VisualizadorDeEstado, titileo_de_led_verde_al_cambiar_a_estado_correcto)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();
    unsigned long tiempo_de_espera = 10UL;

    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoCorrecto);
    visualizador_de_estado->Actualizar(tiempo_de_espera);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_TRUE(mock_controlador_luz->LuzVerdeEncendida());
        for (int j = 0; j < 25; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_FALSE(mock_controlador_luz->LuzVerdeEncendida());
    }

    delete visualizador_de_estado;
    delete mock_controlador_luz;
}

TEST(VisualizadorDeEstado, titileo_de_led_rojo_al_cambiar_a_estado_incorrecto)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();
    unsigned long tiempo_de_espera = 10UL;

    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoIncorrecto);
    visualizador_de_estado->Actualizar(tiempo_de_espera);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_TRUE(mock_controlador_luz->LuzRojaEncendida());
        for (int j = 0; j < 25; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_FALSE(mock_controlador_luz->LuzRojaEncendida());
    }

    delete visualizador_de_estado;
    delete mock_controlador_luz;
}

TEST(VisualizadorDeEstado, titileo_de_led_rojo_y_verde_al_cambiar_a_estado_desconectado)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();
    unsigned long tiempo_de_espera = 10UL;

    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoCorrecto);
    visualizador_de_estado->Actualizar(tiempo_de_espera);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoDesconectado);
    visualizador_de_estado->Actualizar(tiempo_de_espera);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_TRUE(mock_controlador_luz->LuzRojaEncendida());
        EXPECT_TRUE(mock_controlador_luz->LuzVerdeEncendida());
        for (int j = 0; j < 25; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_FALSE(mock_controlador_luz->LuzRojaEncendida());
        EXPECT_FALSE(mock_controlador_luz->LuzVerdeEncendida());
    }

    delete visualizador_de_estado;
    delete mock_controlador_luz;
}

TEST(VisualizadorDeEstado, led_verde_queda_encendido_luego_de_una_espera_mayor_a_las_repeticiones)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();

    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoIncorrecto);
    visualizador_de_estado->Actualizar(10UL);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoCorrecto);

    visualizador_de_estado->Actualizar(200UL);

    EXPECT_FALSE(mock_controlador_luz->LuzVerdeEncendida());

    visualizador_de_estado->Actualizar(8000000UL);

    EXPECT_TRUE(mock_controlador_luz->LuzVerdeEncendida());

    delete visualizador_de_estado;
    delete mock_controlador_luz;
}

TEST(VisualizadorDeEstado, titileo_de_led_rojo_y_verde_al_cambiar_a_estado_ejecutando)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();
    unsigned long tiempo_de_espera = 10UL;

    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoDesconectado);
    visualizador_de_estado->Actualizar(tiempo_de_espera);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoEjecutando);
    visualizador_de_estado->Actualizar(tiempo_de_espera);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_TRUE(mock_controlador_luz->LuzRojaEncendida());
        EXPECT_FALSE(mock_controlador_luz->LuzVerdeEncendida());
        for (int j = 0; j < 25; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_FALSE(mock_controlador_luz->LuzRojaEncendida());
        EXPECT_TRUE(mock_controlador_luz->LuzVerdeEncendida());
    }

    delete visualizador_de_estado;
    delete mock_controlador_luz;
}
