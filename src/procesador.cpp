#include "procesador.hpp"

using namespace dominio;

void Procesador::SetRequest(Request *request)
{
    request_ = request;
}

void Procesador::SetVisualizadorDeEstado(VisualizadorDeEstado *visualizador_de_estado)
{
    visualizador_de_estado_ = visualizador_de_estado;
}

void Procesador::ActualizarEstado() {}