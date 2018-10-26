#include "visualizador_de_estado.hpp"

using namespace dominio;

void VisualizadorDeEstado::SetControladorLed(ControladorLed *controlador_led)
{
    controlador_led_ = controlador_led;
}
void VisualizadorDeEstado::Actualizar(int milisegundos)
{
    controlador_led_->PrenderLedRojo();
    controlador_led_->PrenderLedVerde();
}