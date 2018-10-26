#include "procesador.hpp"
#include "estado_del_build.hpp"

using namespace dominio;

void Procesador::SetRequest(Request *request)
{
    request_ = request;
}

void Procesador::SetVisualizadorDeEstado(VisualizadorDeEstado *visualizador_de_estado)
{
    visualizador_de_estado_ = visualizador_de_estado;
}

void Procesador::ActualizarEstado()
{
    EstadoDelBuild estado_del_build = request_->ObtenerEstado();
    visualizador_de_estado_->SetEstadoDelBuild(estado_del_build);
}