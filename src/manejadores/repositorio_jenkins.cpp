#include "repositorio_jenkins.hpp"
#include "../adaptadores/request_jenkins.hpp"

using namespace manejadores;

RepositorioJenkins::RepositorioJenkins(Procesador *procesador)
{
    procesador_ = procesador;
}

std::string RepositorioJenkins::Responder(std::map<std::string, std::string> datos)
{
    std::string url = datos.find("url")->second;
    std::string repositorio = datos.find("repositorio")->second;
    std::string usuario = datos.find("usuario")->second;
    std::string token = datos.find("token")->second;
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