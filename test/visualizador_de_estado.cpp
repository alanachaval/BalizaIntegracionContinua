#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "adaptadores/controlador_led.hpp"
#include "mocks/mock_controlador_led.cpp"
#include "dominio/visualizador_de_estado.hpp"

using namespace dominio;
using ::testing::AtLeast;
using ::testing::Return;

TEST(VisualizadorDeEstado, inicializa_en_estado_desconectado)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *mock_controlador_led = new MockControladorLed();

    visualizador_de_estado->SetControladorLed(mock_controlador_led);

    EXPECT_TRUE(mock_controlador_led->LedRojoEncendido());
    EXPECT_TRUE(mock_controlador_led->LedVerdeEncendido());

    delete visualizador_de_estado;
    delete mock_controlador_led;
}

TEST(VisualizadorDeEstado, encender_led_verde_al_cambiar_a_estado_correcto)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *mock_controlador_led = new MockControladorLed();
    visualizador_de_estado->SetControladorLed(mock_controlador_led);

    visualizador_de_estado->SetEstadoDelBuild(kEstadoCorrecto);

    EXPECT_FALSE(mock_controlador_led->LedRojoEncendido());
    EXPECT_TRUE(mock_controlador_led->LedVerdeEncendido());

    delete visualizador_de_estado;
    delete mock_controlador_led;
}

TEST(VisualizadorDeEstado, encender_led_rojo_al_cambiar_a_estado_incorrecto)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *mock_controlador_led = new MockControladorLed();
    visualizador_de_estado->SetControladorLed(mock_controlador_led);

    visualizador_de_estado->SetEstadoDelBuild(kEstadoIncorrecto);

    EXPECT_FALSE(mock_controlador_led->LedVerdeEncendido());
    EXPECT_TRUE(mock_controlador_led->LedRojoEncendido());

    delete visualizador_de_estado;
    delete mock_controlador_led;
}

TEST(VisualizadorDeEstado, titileo_de_led_verde_al_cambiar_a_estado_correcto)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *mock_controlador_led = new MockControladorLed();
    unsigned long tiempo_de_espera = 10UL;

    visualizador_de_estado->SetControladorLed(mock_controlador_led);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoCorrecto);
    visualizador_de_estado->Actualizar(tiempo_de_espera);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_TRUE(mock_controlador_led->LedVerdeEncendido());
        for (int j = 0; j < 25; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_FALSE(mock_controlador_led->LedVerdeEncendido());
    }

    delete visualizador_de_estado;
    delete mock_controlador_led;
}

TEST(VisualizadorDeEstado, titileo_de_led_rojo_al_cambiar_a_estado_incorrecto)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *mock_controlador_led = new MockControladorLed();
    unsigned long tiempo_de_espera = 10UL;

    visualizador_de_estado->SetControladorLed(mock_controlador_led);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoIncorrecto);
    visualizador_de_estado->Actualizar(tiempo_de_espera);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_TRUE(mock_controlador_led->LedRojoEncendido());
        for (int j = 0; j < 25; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_FALSE(mock_controlador_led->LedRojoEncendido());
    }

    delete visualizador_de_estado;
    delete mock_controlador_led;
}

TEST(VisualizadorDeEstado, titileo_de_led_rojo_y_verde_al_cambiar_a_estado_desconectado)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *mock_controlador_led = new MockControladorLed();
    unsigned long tiempo_de_espera = 10UL;

    visualizador_de_estado->SetControladorLed(mock_controlador_led);
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
        EXPECT_TRUE(mock_controlador_led->LedRojoEncendido());
        EXPECT_TRUE(mock_controlador_led->LedVerdeEncendido());
        for (int j = 0; j < 25; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_FALSE(mock_controlador_led->LedRojoEncendido());
        EXPECT_FALSE(mock_controlador_led->LedVerdeEncendido());
    }

    delete visualizador_de_estado;
    delete mock_controlador_led;
}

TEST(VisualizadorDeEstado, led_verde_queda_encendido_luego_de_una_espera_mayor_a_las_repeticiones)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *mock_controlador_led = new MockControladorLed();

    visualizador_de_estado->SetControladorLed(mock_controlador_led);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoIncorrecto);
    visualizador_de_estado->Actualizar(10UL);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoCorrecto);

    visualizador_de_estado->Actualizar(200UL);

    EXPECT_FALSE(mock_controlador_led->LedVerdeEncendido());

    visualizador_de_estado->Actualizar(8000000UL);

    EXPECT_TRUE(mock_controlador_led->LedVerdeEncendido());

    delete visualizador_de_estado;
    delete mock_controlador_led;
}
