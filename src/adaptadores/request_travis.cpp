#include "../dominio/estado_del_build.hpp"
#include "request_travis.hpp"
#include <HTTPClient.h>
#include <Arduino.h>

using namespace dominio;
using namespace adaptadores;

EstadoDelBuild RequestTravis::ObtenerEstado()
{
    HTTPClient http;
    http.begin("https://api.travis-ci.com/builds?limit=1");
    http.addHeader("Travis-API-Version", "3", false, false);
    http.addHeader("Authorization", "token some_token", false, false);
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