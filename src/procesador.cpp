#include "procesador.hpp"

using namespace dominio;

EstadoDelBuild Procesador::ObtenerEstado()
{
    return request_->ObtenerEstado();
}

void Procesador::SetRequest(Request *request) {
    request_ = request;
}

void Procesador::SetVisualizadorDeEstado(VisualizadorDeEstado *) {}
void Procesador::ActualizarEstado() {}