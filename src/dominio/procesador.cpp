#include "procesador.hpp"
#include "estado_del_build.hpp"

using namespace dominio;

Procesador::Procesador(){
    request_ = 0;
    visualizador_de_estado_ = 0;
}

void Procesador::SetRequest(Request *request)
{
    if(request_ != 0){
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
    if(request_ != 0){
        EstadoDelBuild estado_del_build = request_->ObtenerEstado();
        visualizador_de_estado_->SetEstadoDelBuild(estado_del_build);
    }
}