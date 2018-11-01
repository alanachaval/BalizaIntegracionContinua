#include "visualizador_de_estado.hpp"

using namespace dominio;

void VisualizadorDeEstado::SetControladorLed(ControladorLed *controlador_led)
{
    controlador_led_ = controlador_led;
    controlador_led_->PrenderLedRojo();
    controlador_led_->PrenderLedVerde();
}

void VisualizadorDeEstado::SetEstadoDelBuild(EstadoDelBuild estado_actual)
{
    estado_actual_ = estado_actual;

    switch (estado_actual_)
    {
    case kEstadoDesconocido:
        controlador_led_->PrenderLedRojo();
        controlador_led_->PrenderLedVerde();
        break;
    case kEstadoCorrecto:
        controlador_led_->PrenderLedVerde();
        controlador_led_->ApagarLedRojo();
        break;
    case kEstadoIncorrecto:
        controlador_led_->ApagarLedVerde();
        controlador_led_->PrenderLedRojo();
        break;
    default:
        controlador_led_->ApagarLedRojo();
        controlador_led_->ApagarLedVerde();
    }
}

void VisualizadorDeEstado::Actualizar(int milisegundos)
{
    if (estado_actual_ != estado_anterior)
    {
        tiempo_de_parpadeos = kTiempoDeCadaParpadeo * 2 * kParpadeosDelLed;
        estado_anterior = estado_actual_;
    }

    if (tiempo_de_parpadeos > 0)
    {
        bool led_encendido = tiempo_de_parpadeos % kTiempoDeCadaParpadeo * 2 < kTiempoDeCadaParpadeo;

        switch (estado_actual_)
        {
        case kEstadoCorrecto:
            if (led_encendido)
            {
                controlador_led_->PrenderLedVerde();
            }
            else
            {
                controlador_led_->ApagarLedVerde();
            }
            break;
        case kEstadoIncorrecto:
            if (led_encendido)
            {
                controlador_led_->PrenderLedRojo();
            }
            else
            {
                controlador_led_->ApagarLedRojo();
            }
            break;
        default:
            break;
        }
        tiempo_de_parpadeos -= milisegundos;
    }
}