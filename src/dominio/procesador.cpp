#include "procesador.hpp"
#include "estado_del_build.hpp"

using namespace dominio;

Procesador::Procesador()
{
    request_ = 0;
    visualizador_de_estado_ = 0;
    estado_del_build_ = kEstadoDesconectado;
}

void Procesador::SetRequest(Request *request)
{
    if (request_ != 0)
    {
        delete request_;
    }
    request_ = request;
}

void Procesador::SetVisualizadorDeEstado(VisualizadorDeEstado *visualizador_de_estado)
{
    visualizador_de_estado_ = visualizador_de_estado;
}

EstadoDelBuild Procesador::GetEstado()
{
    return estado_del_build_;
}

void Procesador::ActualizarEstado()
{
    if (request_ != 0)
    {
        estado_del_build_ = request_->ObtenerEstado();
        visualizador_de_estado_->SetEstadoDelBuild(estado_del_build_);
    }
}