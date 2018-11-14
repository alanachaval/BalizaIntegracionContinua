#include "../dominio/estado_del_build.hpp"
#include "request_jenkins.hpp"
#include <HTTPClient.h>
#include <Arduino.h>
#include <sstream>

using namespace dominio;
using namespace adaptadores;

RequestJenkins::RequestJenkins(std::string url, std::string repositorio, std::string usuario, std::string token)
{
    url_ = url;
    repositorio_ = repositorio;
    std::stringstream usuario_token;
    usuario_token << usuario << ":" << token;
    unsigned char const *usuario_token_char = reinterpret_cast<unsigned const char *>(usuario_token.str().c_str());
    base64_usuario_token_ = this->base64_encode(usuario_token_char, usuario_token.str().length()).c_str();
    Serial.println(base64_usuario_token_.c_str());
    fallos = 0;
    estado = kEstadoDesconectado;
}

EstadoDelBuild RequestJenkins::ObtenerEstado()
{
    HTTPClient http;
    std::stringstream url;
    std::stringstream authorization;
    url << "http://" << url_ << "/job/" << repositorio_ << "/lastBuild/api/json";
    authorization << "basic " << base64_usuario_token_;
    http.begin(url.str().c_str());
    Serial.println(url.str().c_str());
    http.addHeader("Authorization", authorization.str().c_str(), false, false);
    Serial.println(authorization.str().c_str());
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

RequestJenkins::~RequestJenkins() {}

bool RequestJenkins::QuedarseConResultado(const char **payload)
{
    const char *palabraEstado = "\"result\"";
    const char *finDeLineaDeEstado = "\",";
    char *inicioDeEstado = strstr(*payload, palabraEstado);
    bool seEncontroPalabra = inicioDeEstado != NULL;

    if (seEncontroPalabra)
    {
        inicioDeEstado += 9;
        char *finDeEstado = strstr(inicioDeEstado, finDeLineaDeEstado);
        *inicioDeEstado = '\0';
        *finDeEstado = '\0';
        *payload = inicioDeEstado + 1;
    }

    return seEncontroPalabra;
}

EstadoDelBuild RequestJenkins::DecidirEstado(const char *nombreDeEstado)
{
    EstadoDelBuild resultado = kEstadoDesconectado;
    const char *palabraCorrecto = "SUCCESS";
    const char *palabraIncorrecto = "FAILURE";

    Serial.println(nombreDeEstado);

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

static const std::string base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

std::string RequestJenkins::base64_encode(unsigned char const *bytes_to_encode, unsigned int in_len)
{
    std::string ret;
    int i = 0;
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];

    while (in_len--)
    {
        char_array_3[i++] = *(bytes_to_encode++);
        if (i == 3)
        {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for (i = 0; (i < 4); i++)
                ret += base64_chars[char_array_4[i]];
            i = 0;
        }
    }

    if (i)
    {
        for (j = i; j < 3; j++)
            char_array_3[j] = '\0';

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);

        for (j = 0; (j < i + 1); j++)
            ret += base64_chars[char_array_4[j]];

        while ((i++ < 3))
            ret += '=';
    }

    return ret;
}