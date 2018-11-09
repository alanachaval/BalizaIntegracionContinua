#include "repositorio_travis.hpp"
#include "../adaptadores/request_travis.hpp"

using namespace manejadores;

RepositorioTravis::RepositorioTravis(Procesador *procesador)
{
    procesador_ = procesador;
}

std::string RepositorioTravis::Responder(std::map<std::string, std::string> datos)
{
    const char *repositorio = datos.find("repositorio")->second.c_str();
    const char *token = datos.find("token")->second.c_str();
    RequestTravis *request_travis = new RequestTravis(repositorio, token);
    procesador_->SetRequest(request_travis);
    return "OK";
}