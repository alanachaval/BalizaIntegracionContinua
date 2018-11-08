#include "repositorio.hpp"

using namespace manejadores;

Repositorio::Repositorio(Procesador *procesador)
{
    procesador_ = procesador;
}

std::string Repositorio::Responder(std::map<std::string, std::string> datos)
{
    return "";
}