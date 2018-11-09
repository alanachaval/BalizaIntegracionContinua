#include "visualizador_de_estado.hpp"

using namespace dominio;

void VisualizadorDeEstado::SetControladorLed(ControladorLed *controlador_led)
{
    controlador_led_ = controlador_led;
    controlador_led_->PrenderLedRojo();
    controlador_led_->PrenderLedVerde();
    estado_anterior_ = kEstadoEjecutando;
    SetEstadoDelBuild(kEstadoDesconectado);
}

void VisualizadorDeEstado::SetEstadoDelBuild(EstadoDelBuild estado_actual)
{
    estado_actual_ = estado_actual;
    controlador_led_->ApagarLedRojo();
    controlador_led_->ApagarLedVerde();

    switch (estado_actual_)
    {
    case kEstadoEjecutando:
        actualizar_actual_ = &VisualizadorDeEstado::ActualizarEstadoEjecutando;
        break;
    case kEstadoDesconectado:
        actualizar_actual_ = &VisualizadorDeEstado::ActualizarEstadoDesconectado;
        break;
    case kEstadoCorrecto:
        actualizar_actual_ = &VisualizadorDeEstado::ActualizarEstadoCorrecto;
        break;
    case kEstadoIncorrecto:
        actualizar_actual_ = &VisualizadorDeEstado::ActualizarEstadoIncorrecto;
        break;
    }

    if (estado_actual_ != estado_anterior_)
    {
        tiempo_de_parpadeos_ = kTiempoDeCadaParpadeo * 2UL * kParpadeosDelLed;
        estado_anterior_ = estado_actual_;
    }
    animacion_en_ejecucion_ = (this->*((dominio::VisualizadorDeEstado *)this)->dominio::VisualizadorDeEstado::actualizar_actual_)(0UL);
}

void VisualizadorDeEstado::Actualizar(unsigned long milisegundos)
{
    if (animacion_en_ejecucion_)
    {
        (this->*((dominio::VisualizadorDeEstado *)this)->dominio::VisualizadorDeEstado::actualizar_actual_)(milisegundos);
    }

    tiempo_desde_ultimo_cambio_ += milisegundos;
}

bool VisualizadorDeEstado::ActualizarEstadoCorrecto(unsigned long milisegundos)
{
    bool seguir_actualizando = true;
    bool led_encendido = tiempo_de_parpadeos_ < milisegundos;
    tiempo_de_parpadeos_ -= milisegundos;
    if (led_encendido)
    {
        tiempo_de_parpadeos_ = 0;
        seguir_actualizando = false;
    }
    led_encendido |= tiempo_de_parpadeos_ % kTiempoDeCadaParpadeo * 2UL < kTiempoDeCadaParpadeo;
    if (led_encendido)
    {
        controlador_led_->PrenderLedVerde();
    }
    else
    {
        controlador_led_->ApagarLedVerde();
    }
    return seguir_actualizando;
}

bool VisualizadorDeEstado::ActualizarEstadoIncorrecto(unsigned long milisegundos)
{
    bool seguir_actualizando = true;
    bool led_encendido = tiempo_de_parpadeos_ < milisegundos;
    tiempo_de_parpadeos_ -= milisegundos;
    if (led_encendido)
    {
        tiempo_de_parpadeos_ = 0;
        seguir_actualizando = false;
    }
    led_encendido |= tiempo_de_parpadeos_ % kTiempoDeCadaParpadeo * 2UL < kTiempoDeCadaParpadeo;
    if (led_encendido)
    {
        controlador_led_->PrenderLedRojo();
    }
    else
    {
        controlador_led_->ApagarLedRojo();
    }
    return seguir_actualizando;
}

bool VisualizadorDeEstado::ActualizarEstadoDesconectado(unsigned long milisegundos)
{
    bool seguir_actualizando = true;
    bool led_encendido = tiempo_de_parpadeos_ < milisegundos;
    tiempo_de_parpadeos_ -= milisegundos;
    if (led_encendido)
    {
        tiempo_de_parpadeos_ = 0;
        seguir_actualizando = false;
    }
    led_encendido |= tiempo_de_parpadeos_ % kTiempoDeCadaParpadeo * 2UL < kTiempoDeCadaParpadeo;
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
    return seguir_actualizando;
}

bool VisualizadorDeEstado::ActualizarEstadoEjecutando(unsigned long milisegundos)
{
    bool led_encendido = tiempo_de_parpadeos_ < milisegundos;
    tiempo_de_parpadeos_ -= milisegundos;
    led_encendido |= tiempo_de_parpadeos_ % kTiempoDeCadaParpadeo * 2UL < kTiempoDeCadaParpadeo;
    if (led_encendido)
    {
        controlador_led_->PrenderLedRojo();
        controlador_led_->ApagarLedVerde();
    }
    else
    {
        controlador_led_->PrenderLedVerde();
        controlador_led_->ApagarLedRojo();
    }
    return true;
}