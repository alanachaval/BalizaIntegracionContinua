#include <Arduino.h>
#include <WiFi.h>
#include <vector>
#include <string>
#include "servidor_wifi.hpp"
#include "../manejadores/manejador.hpp"
#include "../manejadores/index.hpp"
#include "../manejadores/repositorio_travis.hpp"
#include "../manejadores/repositorio_jenkins.hpp"
#include "../manejadores/red.hpp"
#include "../manejadores/estado.hpp"

using namespace adaptadores;

WiFiServer server(80);

ServidorWiFi::ServidorWiFi(Procesador *procesador, ClienteWiFi *cliente_wifi)
{
    manejadores_.insert(std::pair<std::string, manejadores::Manejador *>("/", new manejadores::Index()));
    manejadores_.insert(std::pair<std::string, manejadores::Manejador *>("/repositorio_travis", new manejadores::RepositorioTravis(procesador)));
    manejadores_.insert(std::pair<std::string, manejadores::Manejador *>("/repositorio_jenkins", new manejadores::RepositorioJenkins(procesador)));
    manejadores_.insert(std::pair<std::string, manejadores::Manejador *>("/red", new manejadores::Red(cliente_wifi)));
    manejadores_.insert(std::pair<std::string, manejadores::Manejador *>("/estado", new manejadores::Estado(procesador, cliente_wifi)));
}

void ServidorWiFi::Iniciar(const char *ssid, const char *password)
{
    WiFi.softAP(ssid, password);
    server.begin();
}

const char *ServidorWiFi::ObtenerIP()
{
    return WiFi.softAPIP().toString().c_str();
}

void ServidorWiFi::AtenderCliente()
{
    // Se utilizan los parametros por referencia para evitar copias de std::string
    // std::string copia el valor en cada asignacion
    // http://www.cplusplus.com/reference/string/string/string/

    WiFiClient cliente = server.available();
    std::vector<std::string> request;
    std::map<std::string, std::string> datos;
    bool es_post = false;
    int fin_header = 0;
    cliente.setTimeout(1);

    if (cliente)
    {
        Serial.println("Cliente conectado.");
        LeerRequest(&cliente, &request, &fin_header, &es_post);
        if (es_post)
        {
            AnalizarPayload(fin_header, &request, &datos);
        }
        if (cliente.connected() && fin_header > 0)
        {
            EnviarRespuesta(&cliente, &request, &datos);
        }
        cliente.stop();
        Serial.println("Cliente disconectado.\n");
    }
}

void ServidorWiFi::LeerRequest(WiFiClient *cliente, std::vector<std::string> *request, int *fin_header, bool *es_post)
{
    cliente->setTimeout(1);
    bool continuar_leyendo = true;
    Serial.print("Header Inicial: ");
    Serial.println(*fin_header);
    while (cliente->connected() && continuar_leyendo)
    {
        if (cliente->available())
        {
            String pedido = cliente->readStringUntil('\n');
            pedido.replace("\r", "");
            request->push_back(pedido.c_str());
            Serial.print("Pedido: ");
            Serial.println(pedido.c_str());
            //Si la linea esta vacia entonces se termino el header o el payload
            if (pedido.length() < 3)
            {
                continuar_leyendo = *fin_header == 0;
                if (continuar_leyendo)
                {
                    *fin_header = request->size();
                    // Luego de la primer linea vacia si es post siguie leyendo
                    *es_post = (*fin_header) > 0 && (memcmp(request->at(0).c_str(), "POST", 4) == 0);
                    continuar_leyendo = *es_post;
                }
                Serial.print("Header: ");
                Serial.println(*fin_header);
            }
        }
    }
}

void ServidorWiFi::AnalizarPayload(int fin_header, std::vector<std::string> *request, std::map<std::string, std::string> *datos)
{
    for (int i = fin_header; i < request->size(); i++)
    {
        std::string *linea = &(request->at(i));
        size_t separador = linea->find(':');
        std::string clave = linea->substr(0, separador);
        Serial.print("clave:");
        Serial.println(clave.c_str());
        std::string valor = linea->substr(separador + 1, linea->length() - separador - 1);
        Serial.print("valor");
        Serial.println(valor.c_str());
        datos->insert(std::pair<std::string, std::string>(clave, valor));
    }
}

void ServidorWiFi::EnviarRespuesta(WiFiClient *cliente, std::vector<std::string> *request, std::map<std::string, std::string> *datos)
{
    (*cliente).println("HTTP/1.1 200 OK");
    (*cliente).println("Content-type:text/html");
    (*cliente).println("Connection: close");
    (*cliente).println();

    std::string *primera_linea = &(request->at(0));
    size_t first = primera_linea->find(' ');
    size_t last = primera_linea->find(' ', first + 1);
    std::string url = primera_linea->substr(first + 1, last - first - 1);
    Serial.println(url.c_str());

    std::map<std::string, manejadores::Manejador *>::iterator par = manejadores_.find(url);

    if (par == manejadores_.end()) //Esto indica que la clave no esta en el diccionario
    {
        (*cliente).println("ERROR 404");
    }
    else
    {
        manejadores::Manejador *manejador = par->second;
        (*cliente).println(manejador->Responder(datos).c_str());
    }
    (*cliente).println();
}
