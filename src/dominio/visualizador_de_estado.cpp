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
    case kEstadoDesconectado:
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
    }
}

void VisualizadorDeEstado::Actualizar(unsigned long milisegundos)
{
    if (estado_actual_ != estado_anterior_)
    {
        tiempo_de_parpadeos_ = kTiempoDeCadaParpadeo * 2UL * kParpadeosDelLed;
        estado_anterior_ = estado_actual_;
    }

    if (tiempo_de_parpadeos_ > 0)
    {
        //Si se termina el tiempo los deja encendidos, en caso de demoras en otras ejecuciones
        bool led_encendido = tiempo_de_parpadeos_ < milisegundos;
        tiempo_de_parpadeos_ -= milisegundos;
        if (led_encendido)
        {
            tiempo_de_parpadeos_ = 0;
        }

        led_encendido |= tiempo_de_parpadeos_ % kTiempoDeCadaParpadeo * 2UL < kTiempoDeCadaParpadeo;

        switch (estado_actual_)
        {
        case kEstadoDesconectado:
            if (led_encendido)
            {
                controlador_led_->PrenderLedRojo();
                controlador_led_->PrenderLedVerde();
            }
            else
            {
                controlador_led_->ApagarLedRojo();
                controlador_led_->ApagarLedVerde();
            }
            break;
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
        }
    }
}
