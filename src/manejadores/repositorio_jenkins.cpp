#include "repositorio_jenkins.hpp"
#include "../adaptadores/request_jenkins.hpp"

using namespace manejadores;

RepositorioJenkins::RepositorioJenkins(Procesador *procesador)
{
    procesador_ = procesador;
}

std::string RepositorioJenkins::Responder(std::map<std::string, std::string> datos)
{
    const char *url = datos.find("url")->second.c_str();
    const char *repositorio = datos.find("repositorio")->second.c_str();
    const char *usuario = datos.find("usuario")->second.c_str();
    const char *token = datos.find("token")->second.c_str();
    RequestJenkins *request_jenkins = new RequestJenkins(url, repositorio, usuario, token);
    procesador_->SetRequest(request_jenkins);
    return "OK";
}

/*std::string RepositorioJenkins::ObtenerDatos() {
    return "{"
        "\"nombre\": \"jenkins\""
        "\"campos\": ["
            "\"url\","
            "\"repositorio\","
            "\"usuario\","
            "\"token\""
        "]"
    "}";
}*/