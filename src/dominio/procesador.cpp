#include "procesador.hpp"
#include "estado_del_build.hpp"

using namespace dominio;

Procesador::Procesador(){
    request_ = nullptr;
    visualizador_de_estado_ = nullptr;
}

void Procesador::SetRequest(Request *request)
{
    if(request_ != nullptr){
        delete request_;
    }
    request_ = request;
}

void Procesador::SetVisualizadorDeEstado(VisualizadorDeEstado *visualizador_de_estado)
{
    visualizador_de_estado_ = visualizador_de_estado;
}

void Procesador::ActualizarEstado()
{
    if(request_ != nullptr){
        EstadoDelBuild estado_del_build = request_->ObtenerEstado();
        visualizador_de_estado_->SetEstadoDelBuild(estado_del_build);
    }
}