#include "visualizador_de_estado.hpp"

using namespace dominio;

void VisualizadorDeEstado::SetControladorLuz(ControladorLuz *controlador_luz)
{
    controlador_luz_ = controlador_luz;
    controlador_luz_->ApagarLuzRoja();
    controlador_luz_->ApagarLuzVerde();
    controlador_luz_->PrenderLuzAmarilla();
    estado_anterior_ = kEstadoEjecutando;
    SetEstadoDelBuild(kEstadoDesconectado);
}

void VisualizadorDeEstado::SetEstadoDelBuild(EstadoDelBuild estado_actual)
{
    estado_anterior_ = estado_actual_;
    estado_actual_ = estado_actual;

    switch (estado_actual_)
    {
    case kEstadoEjecutando:
        actualizar_actual_ = &VisualizadorDeEstado::ActualizarEstadoEjecutando;
        break;
    case kEstadoDesconectado:
        controlador_luz_->ApagarLuzRoja();
        controlador_luz_->ApagarLuzVerde();
        actualizar_actual_ = &VisualizadorDeEstado::ActualizarEstadoDesconectado;
        break;
    case kEstadoCorrecto:
        controlador_luz_->ApagarLuzRoja();
        controlador_luz_->ApagarLuzAmarilla();
        actualizar_actual_ = &VisualizadorDeEstado::ActualizarEstadoCorrecto;
        break;
    case kEstadoIncorrecto:
        controlador_luz_->ApagarLuzVerde();
        controlador_luz_->ApagarLuzAmarilla();
        actualizar_actual_ = &VisualizadorDeEstado::ActualizarEstadoIncorrecto;
        break;
    }

    if (estado_actual_ != estado_anterior_)
    {
        tiempo_de_parpadeos_ = kTiempoDeCadaParpadeo * 2UL * kParpadeosDeLuz;
        animacion_en_ejecucion_ = true;
    }
    (this->*actualizar_actual_)(true);
}

void VisualizadorDeEstado::Actualizar(unsigned long milisegundos)
{
    if (animacion_en_ejecucion_)
    {
        bool led_encendido = tiempo_de_parpadeos_ < milisegundos;
        tiempo_de_parpadeos_ -= milisegundos;
        if (led_encendido)
        {
            tiempo_de_parpadeos_ = 0;
            animacion_en_ejecucion_ = false;
        }
        // La division del tiempo desde el cambio de estado y el tiempo de parpadeo es par
        // EJ: 1350 / 500 = 2 (0b...10) => encendido, 870 / 500 = 1 (0b...1) => apagado
        led_encendido |= !((tiempo_de_parpadeos_ / kTiempoDeCadaParpadeo) & 0b1);
        (this->*actualizar_actual_)(led_encendido);
    }
}

void VisualizadorDeEstado::ActualizarEstadoCorrecto(bool led_encendido)
{
    if (led_encendido)
    {
        controlador_luz_->PrenderLuzVerde();
    }
    else
    {
        controlador_luz_->ApagarLuzVerde();
    }
}

void VisualizadorDeEstado::ActualizarEstadoIncorrecto(bool led_encendido)
{
    if (led_encendido)
    {
        controlador_luz_->PrenderLuzRoja();
    }
    else
    {
        controlador_luz_->ApagarLuzRoja();
    }
}

void VisualizadorDeEstado::ActualizarEstadoDesconectado(bool led_encendido)
{
    if (led_encendido)
    {
        controlador_luz_->PrenderLuzAmarilla();
    }
    else
    {
        controlador_luz_->ApagarLuzAmarilla();
    }
}

void VisualizadorDeEstado::ActualizarEstadoEjecutando(bool led_encendido)
{
    if (led_encendido)
    {
        controlador_luz_->PrenderLuzAmarilla();
    }
    else
    {
        controlador_luz_->ApagarLuzAmarilla();
    }
}