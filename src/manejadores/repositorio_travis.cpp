#include "repositorio_travis.hpp"
#include "../adaptadores/request_travis.hpp"

using namespace manejadores;

RepositorioTravis::RepositorioTravis(Procesador *procesador)
{
    procesador_ = procesador;
}

std::string RepositorioTravis::Responder(std::map<std::string, std::string> *datos)
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
    std::map<std::string, std::string>::iterator token = datos->find("token");
    if (token == datos->end())
    {
        return "Error : sin parametro token";
    }
    RequestTravis *request_travis = new RequestTravis(url->second, repositorio->second, token->second);
    procesador_->SetRequest(request_travis);
    return "OK";
}

/*std::string RepositorioTravis::ObtenerDatos() {
    return "{"
        "\"nombre\": \"travis\""
        "\"campos\": ["
            "\"repositorio\","
            "\"token\""
        "]"
    "}";
}*/