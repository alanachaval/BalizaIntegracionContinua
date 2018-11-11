#include "repositorio_jenkins.hpp"
#include "../adaptadores/request_jenkins.hpp"

using namespace manejadores;

RepositorioJenkins::RepositorioJenkins(Procesador *procesador)
{
    procesador_ = procesador;
}

std::string RepositorioJenkins::Responder(std::map<std::string, std::string> *datos)
{
    std::map<std::string, std::string>::iterator url = datos->find("url");
    if (url == datos->end())
    {
        return "Error : sin parametro url";
    }
    std::map<std::string, std::string>::iterator repositorio = datos->find("repositorio");
    if (repositorio == datos->end())
    {
        return "Error : sin parametro repositorio";
    }
    std::map<std::string, std::string>::iterator usuario = datos->find("usuario");
    if (usuario == datos->end())
    {
        return "Error : sin parametro usuario";
    }
    std::map<std::string, std::string>::iterator token = datos->find("token");
    if (token == datos->end())
    {
        return "Error : sin parametro token";
    }
    RequestJenkins *request_jenkins = new RequestJenkins(url->second, repositorio->second, usuario->second, token->second);
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