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

    EXPECT_TRUE(mock_controlador_luz->LuzAmarillaEncendida());
    EXPECT_FALSE(mock_controlador_luz->LuzRojaEncendida());
    EXPECT_FALSE(mock_controlador_luz->LuzVerdeEncendida());

    delete visualizador_de_estado;
    delete mock_controlador_luz;
}

TEST(VisualizadorDeEstado, encender_luz_verde_al_cambiar_a_estado_correcto)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();
    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);

    visualizador_de_estado->SetEstadoDelBuild(kEstadoCorrecto);

    EXPECT_TRUE(mock_controlador_luz->LuzVerdeEncendida());
    EXPECT_FALSE(mock_controlador_luz->LuzRojaEncendida());
    EXPECT_FALSE(mock_controlador_luz->LuzAmarillaEncendida());

    delete visualizador_de_estado;
    delete mock_controlador_luz;
}

TEST(VisualizadorDeEstado, encender_luz_rojo_al_cambiar_a_estado_incorrecto)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();
    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);

    visualizador_de_estado->SetEstadoDelBuild(kEstadoIncorrecto);

    EXPECT_FALSE(mock_controlador_luz->LuzVerdeEncendida());
    EXPECT_TRUE(mock_controlador_luz->LuzRojaEncendida());
    EXPECT_FALSE(mock_controlador_luz->LuzAmarillaEncendida());

    delete visualizador_de_estado;
    delete mock_controlador_luz;
}

TEST(VisualizadorDeEstado, titileo_de_luz_verde_al_cambiar_a_estado_correcto)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();
    unsigned long tiempo_de_espera = 10UL;
    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoCorrecto);

    EXPECT_TRUE(mock_controlador_luz->LuzVerdeEncendida());
    for (int i = 0; i < VisualizadorDeEstado::kParpadeosDeLuz; i++)
    {
        for (int j = 0; j < VisualizadorDeEstado::kTiempoDeCadaParpadeo / tiempo_de_espera; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_FALSE(mock_controlador_luz->LuzVerdeEncendida());
        for (int j = 0; j < VisualizadorDeEstado::kTiempoDeCadaParpadeo / tiempo_de_espera; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_TRUE(mock_controlador_luz->LuzVerdeEncendida());
    }

    delete visualizador_de_estado;
    delete mock_controlador_luz;
}

TEST(VisualizadorDeEstado, titileo_de_luz_roja_al_cambiar_a_estado_incorrecto)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();
    unsigned long tiempo_de_espera = 10UL;
    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoIncorrecto);

    EXPECT_TRUE(mock_controlador_luz->LuzRojaEncendida());
    for (int i = 0; i < VisualizadorDeEstado::kParpadeosDeLuz; i++)
    {
        for (int j = 0; j < VisualizadorDeEstado::kTiempoDeCadaParpadeo / tiempo_de_espera; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_FALSE(mock_controlador_luz->LuzRojaEncendida());
        for (int j = 0; j < VisualizadorDeEstado::kTiempoDeCadaParpadeo / tiempo_de_espera; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_TRUE(mock_controlador_luz->LuzRojaEncendida());
    }

    delete visualizador_de_estado;
    delete mock_controlador_luz;
}

TEST(VisualizadorDeEstado, titileo_de_luz_amarilla_al_cambiar_a_estado_desconectado)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();
    unsigned long tiempo_de_espera = 10UL;
    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoCorrecto);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoDesconectado);

    EXPECT_TRUE(mock_controlador_luz->LuzAmarillaEncendida());
    for (int i = 0; i < VisualizadorDeEstado::kParpadeosDeLuz; i++)
    {
        for (int j = 0; j < VisualizadorDeEstado::kTiempoDeCadaParpadeo / tiempo_de_espera; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_FALSE(mock_controlador_luz->LuzAmarillaEncendida());
        for (int j = 0; j < VisualizadorDeEstado::kTiempoDeCadaParpadeo / tiempo_de_espera; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_TRUE(mock_controlador_luz->LuzAmarillaEncendida());
    }

    delete visualizador_de_estado;
    delete mock_controlador_luz;
}

TEST(VisualizadorDeEstado, luz_verde_queda_encendida_luego_de_una_espera_menor_al_parpadeo)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();
    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoIncorrecto);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoCorrecto);

    visualizador_de_estado->Actualizar(VisualizadorDeEstado::kTiempoDeCadaParpadeo * 2 / 3);

    EXPECT_FALSE(mock_controlador_luz->LuzVerdeEncendida());

    delete visualizador_de_estado;
    delete mock_controlador_luz;
}

TEST(VisualizadorDeEstado, luz_verde_queda_encendida_luego_de_una_espera_mayor_a_todas_las_repeticiones)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();
    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoIncorrecto);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoCorrecto);

    visualizador_de_estado->Actualizar(VisualizadorDeEstado::kTiempoDeCadaParpadeo * VisualizadorDeEstado::kParpadeosDeLuz * 3);

    EXPECT_TRUE(mock_controlador_luz->LuzVerdeEncendida());

    delete visualizador_de_estado;
    delete mock_controlador_luz;
}

TEST(VisualizadorDeEstado, titileo_de_luz_amarilla_manteniendo_la_verde_encendida_al_cambiar_a_estado_ejecutando_desde_estado_correcto)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();
    unsigned long tiempo_de_espera = 10UL;
    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoCorrecto);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoEjecutando);

    EXPECT_TRUE(mock_controlador_luz->LuzVerdeEncendida());
    EXPECT_TRUE(mock_controlador_luz->LuzAmarillaEncendida());
    for (int i = 0; i < VisualizadorDeEstado::kParpadeosDeLuz; i++)
    {
        for (int j = 0; j < VisualizadorDeEstado::kTiempoDeCadaParpadeo / tiempo_de_espera; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_TRUE(mock_controlador_luz->LuzVerdeEncendida());
        EXPECT_FALSE(mock_controlador_luz->LuzAmarillaEncendida());
        for (int j = 0; j < VisualizadorDeEstado::kTiempoDeCadaParpadeo / tiempo_de_espera; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_TRUE(mock_controlador_luz->LuzVerdeEncendida());
        EXPECT_TRUE(mock_controlador_luz->LuzAmarillaEncendida());
    }

    delete visualizador_de_estado;
    delete mock_controlador_luz;
}

TEST(VisualizadorDeEstado, titileo_de_luz_amarilla_manteniendo_la_roja_encendida_al_cambiar_a_estado_ejecutando_desde_estado_incorrecto)
{
    VisualizadorDeEstado *visualizador_de_estado = new VisualizadorDeEstado();
    MockControladorLuz *mock_controlador_luz = new MockControladorLuz();
    unsigned long tiempo_de_espera = 10UL;
    visualizador_de_estado->SetControladorLuz(mock_controlador_luz);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoCorrecto);
    visualizador_de_estado->SetEstadoDelBuild(kEstadoEjecutando);

    EXPECT_TRUE(mock_controlador_luz->LuzVerdeEncendida());
    EXPECT_TRUE(mock_controlador_luz->LuzAmarillaEncendida());
    for (int i = 0; i < VisualizadorDeEstado::kParpadeosDeLuz; i++)
    {
        for (int j = 0; j < VisualizadorDeEstado::kTiempoDeCadaParpadeo / tiempo_de_espera; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_TRUE(mock_controlador_luz->LuzVerdeEncendida());
        EXPECT_FALSE(mock_controlador_luz->LuzAmarillaEncendida());
        for (int j = 0; j < VisualizadorDeEstado::kTiempoDeCadaParpadeo / tiempo_de_espera; j++)
        {
            visualizador_de_estado->Actualizar(tiempo_de_espera);
        }
        EXPECT_TRUE(mock_controlador_luz->LuzVerdeEncendida());
        EXPECT_TRUE(mock_controlador_luz->LuzAmarillaEncendida());
    }

    delete visualizador_de_estado;
    delete mock_controlador_luz;
}
