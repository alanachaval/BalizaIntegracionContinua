#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "adaptadores/controlador_led.hpp"
#include "mocks/mock_controlador_led.cpp"
#include "dominio/visualizador_de_estado.hpp"

using namespace dominio;
using ::testing::AtLeast;
using ::testing::Return;

TEST(VisualizadorDeEstado, inicializa_en_estado_desconocido)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *controlador_led = new MockControladorLed();

    visualizador_de_estado->SetControladorLed(controlador_led);

    EXPECT_TRUE(controlador_led->LedRojoEncendido());
    EXPECT_TRUE(controlador_led->LedVerdeEncendido());

    delete visualizador_de_estado;
    delete controlador_led;
}

TEST(VisualizadorDeEstado, encender_led_verde_al_cambiar_a_estado_correcto)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *controlador_led = new MockControladorLed();
    visualizador_de_estado->SetControladorLed(controlador_led);

    visualizador_de_estado->SetEstadoDelBuild(kEstadoCorrecto);

    EXPECT_FALSE(controlador_led->LedRojoEncendido());
    EXPECT_TRUE(controlador_led->LedVerdeEncendido());

    delete visualizador_de_estado;
    delete controlador_led;
}

TEST(VisualizadorDeEstado, encender_led_rojo_al_cambiar_a_estado_incorrecto)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *controlador_led = new MockControladorLed();
    visualizador_de_estado->SetControladorLed(controlador_led);

    visualizador_de_estado->SetEstadoDelBuild(kEstadoIncorrecto);

    EXPECT_FALSE(controlador_led->LedVerdeEncendido());
    EXPECT_TRUE(controlador_led->LedRojoEncendido());

    delete visualizador_de_estado;
    delete controlador_led;
}

TEST(VisualizadorDeEstado, titileo_de_led_verde_al_cambiar_a_estado_correcto)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *controlador_led = new MockControladorLed();

    visualizador_de_estado->SetControladorLed(controlador_led);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoCorrecto);
    visualizador_de_estado->Actualizar(20);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            visualizador_de_estado->Actualizar(10);
        }
        EXPECT_TRUE(controlador_led->LedVerdeEncendido());
        for (int j = 0; j < 25; j++)
        {
            visualizador_de_estado->Actualizar(10);
        }
        EXPECT_FALSE(controlador_led->LedVerdeEncendido());
    }

    delete visualizador_de_estado;
    delete controlador_led;
}

TEST(VisualizadorDeEstado, titileo_de_led_rojo_al_cambiar_a_estado_incorrecto)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLed *controlador_led = new MockControladorLed();

    visualizador_de_estado->SetControladorLed(controlador_led);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoIncorrecto);
    visualizador_de_estado->Actualizar(20);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            visualizador_de_estado->Actualizar(10);
        }
        EXPECT_TRUE(controlador_led->LedRojoEncendido());
        for (int j = 0; j < 25; j++)
        {
            visualizador_de_estado->Actualizar(10);
        }
        EXPECT_FALSE(controlador_led->LedRojoEncendido());
    }

    delete visualizador_de_estado;
    delete controlador_led;
}
