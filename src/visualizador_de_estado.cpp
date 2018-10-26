#include "visualizador_de_estado.hpp"

using namespace dominio;

void VisualizadorDeEstado::SetControladorLed(ControladorLed *controlador_led)
{
    controlador_led_ = controlador_led;
}

void VisualizadorDeEstado::SetEstadoDelBuild(EstadoDelBuild estado_del_build)
{
    estado_del_build_ = estado_del_build;
}

void VisualizadorDeEstado::Actualizar(int milisegundos)
{
    switch (estado_del_build_)
    {
    case kEstadoCorrecto:
        controlador_led_->PrenderLedVerde();
        controlador_led_->ApagarLedRojo();
        break;
    case kEstadoDesconocido:
        controlador_led_->PrenderLedRojo();
        controlador_led_->PrenderLedVerde();
        break;
    default:
        controlador_led_->ApagarLedRojo();
        controlador_led_->ApagarLedVerde();
    }
}