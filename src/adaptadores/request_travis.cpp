#include "../dominio/estado_del_build.hpp"
#include "request_travis.hpp"
#include <HTTPClient.h>
#include <Arduino.h>
#include <sstream>

using namespace dominio;
using namespace adaptadores;

RequestTravis::RequestTravis(const char *repositorio, const char *token)
{
    repositorio_ = repositorio;
    token_ = token;
    fallos = 0;
    estado = kEstadoDesconectado;
}

EstadoDelBuild RequestTravis::ObtenerEstado()
{
    HTTPClient http;
    std::stringstream url;
    std::stringstream token;
    url << "https://api.travis-ci.org/repo/" << repositorio_ << "/builds?limit=1";
    token << "token " << token_;
    http.begin(url.str().c_str());
    http.addHeader("Travis-API-Version", "3", false, false);
    http.addHeader("Authorization", token.str().c_str(), false, false);
    int httpCode = http.GET();

    if (httpCode > 0)
    {
        String payload = http.getString();
        const char *payloadComoChar = payload.c_str();
        fallos = 0;
        Serial.println(httpCode);
        Serial.println(payload);

        if (QuedarseConResultado(&payloadComoChar))
        {
            estado = DecidirEstado(payloadComoChar);
        }

        Serial.println(payloadComoChar);
    }
    else
    {
        fallos++;
        if (fallos > 3)
        {
            estado = kEstadoDesconectado;
        }
        Serial.println("Error on HTTP request");
    }

    http.end();

    return estado;
}

RequestTravis::~RequestTravis() {}

bool RequestTravis::QuedarseConResultado(const char **payload)
{
    const char *palabraEstado = "state";
    const char *finDeLineaDeEstado = "\",";
    char *inicioDeEstado = strstr(*payload, palabraEstado);
    bool seEncontroPalabra = inicioDeEstado != NULL;

    if (seEncontroPalabra)
    {
        inicioDeEstado += 8;
        char *finDeEstado = strstr(inicioDeEstado, finDeLineaDeEstado);
        *inicioDeEstado = '\0';
        *finDeEstado = '\0';
        *payload = inicioDeEstado + 1;
    }

    return seEncontroPalabra;
}

EstadoDelBuild RequestTravis::DecidirEstado(const char *nombreDeEstado)
{
    EstadoDelBuild resultado = kEstadoDesconectado;
    const char *palabraCorrecto = "passed";
    const char *palabraIncorrecto = "failed";

    if (!strcmp(nombreDeEstado, palabraCorrecto))
    {
        resultado = kEstadoCorrecto;
    }
    else if (!strcmp(nombreDeEstado, palabraIncorrecto))
    {
        resultado = kEstadoIncorrecto;
    }
    else
    {
        resultado = kEstadoEjecutando;
    }

    return resultado;
}