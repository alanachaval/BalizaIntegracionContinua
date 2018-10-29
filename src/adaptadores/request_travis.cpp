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
}

EstadoDelBuild RequestTravis::ObtenerEstado()
{
    HTTPClient http;
    std::stringstream url;
    std::stringstream token;
    url << "https://api.travis-ci.com/repo/" << repositorio_ << "/builds?limit=1";
    token << "token " << token_;
    http.begin(url.str().c_str());
    http.addHeader("Travis-API-Version", "3", false, false);
    http.addHeader("Authorization", token.str().c_str(), false, false);
    int httpCode = http.GET();

    if (httpCode > 0)
    {
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
    }
    else
    {
        Serial.println("Error on HTTP request");
    }

    http.end();

    return kEstadoDesconocido;
}

const char *StringEstado(const char *payload)
{
}