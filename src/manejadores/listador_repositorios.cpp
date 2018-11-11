#include <sstream>
#include "listador_repositorios.hpp"
#include "repositorio_travis.hpp"
#include "repositorio_jenkins.hpp"

using namespace manejadores;

std::string ListadorRepositorios::Responder(std::map<std::string, std::string> *datos)
{
    std::stringstream listado;

    listado << "[" << datos->find("travis")->second.c_str() << ", "
            << datos->find("jenkins")->second.c_str() << "]";
    return listado.str();
}