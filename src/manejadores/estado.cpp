#include "estado.hpp"
#include "../adaptadores/cliente_wifi.hpp"
#include "../dominio/estado_del_build.hpp"
#include "../dominio/procesador.hpp"
#include <sstream>

using namespace manejadores;
using namespace dominio;

Estado::Estado(dominio::Procesador *procesador, adaptadores::ClienteWiFi *cliente_wifi)
{
    procesador_ = procesador;
    cliente_wifi_ = cliente_wifi;
}

std::string Estado::Responder(std::map<std::string, std::string> *datos)
{
    const char *estado_conexion;
    if (cliente_wifi_->EstaConectado())
    {
        estado_conexion = "Conectado";
    }
    else
    {
        estado_conexion = "Desconectado";
    }
    const char *estado_integracion_continua;
    EstadoDelBuild estado_del_build = procesador_->GetEstado();
    switch (estado_del_build)
    {
    case kEstadoEjecutando:
        estado_integracion_continua = "Ejecutando";
        break;
    case kEstadoDesconectado:
        estado_integracion_continua = "Desconectado";
        break;
    case kEstadoCorrecto:
        estado_integracion_continua = "Correcto";
        break;
    case kEstadoIncorrecto:
        estado_integracion_continua = "Incorrecto";
        break;
    default:
        estado_integracion_continua = "";
        break;
    }
    std::stringstream respuesta;
    respuesta << "Estado Conexion: " << estado_conexion << "\r\nEstado Integracion Continua: " << estado_integracion_continua;
    return respuesta.str();
}