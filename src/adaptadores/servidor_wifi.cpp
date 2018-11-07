#include <Arduino.h>
#include <WiFi.h>
#include <vector>
#include <string>
#include "servidor_wifi.hpp"
#include "../manejadores/manejador.hpp"
#include "../manejadores/index.hpp"
#include "../manejadores/repositorio.hpp"
#include "../manejadores/red.hpp"

using namespace adaptadores;

WiFiServer server(80);

ServidorWiFi::ServidorWiFi()
{
    manejadores_.insert(std::pair<std::string, manejadores::Manejador *>("/", new manejadores::Index()));
    manejadores_.insert(std::pair<std::string, manejadores::Manejador *>("/repositorio", new manejadores::Repositorio()));
    manejadores_.insert(std::pair<std::string, manejadores::Manejador *>("/red", new manejadores::Red()));
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
    WiFiClient client = server.available(); // Listen for incoming clients

    std::vector<String> request;

    if (client)
    { // If a new client connects,
        client.setTimeout(1);
        Serial.println("New Client."); // print a message out in the serial port
        String currentLine = "";       // make a String to hold incoming data from the client
        while (client.connected())
        { // loop while the client's connected
            if (client.available())
            { // if there's bytes to read from the client,
                String pedido = client.readStringUntil('\n');
                request.push_back(pedido);
                Serial.println(pedido.c_str());
                //Si la linea esta vacia entonces se termino el header
                if (pedido.length() < 3)
                {
                    std::map<std::string, std::string> datos;

                    //Si es un post falta leer el payload
                    if (request[0].startsWith("POST"))
                    {
                        pedido = client.readStringUntil('\n');
                        while (pedido.length() >= 3)
                        {
                            request.push_back(pedido);
                            Serial.println(pedido.c_str());
                            unsigned separador = pedido.indexOf(':');
                            std::string clave = pedido.substring(0, separador).c_str();
                            std::string valor = pedido.substring(separador + 1).c_str();
                            datos.insert(std::pair<std::string, std::string>(clave, valor));
                            Serial.println("clave");
                            Serial.println(clave.c_str());
                            Serial.println("valor");
                            Serial.println(valor.c_str());
                            pedido = client.readStringUntil('\n');
                        };
                    }

                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-type:text/html");
                    client.println("Connection: close");
                    client.println();

                    unsigned first = request[0].indexOf(' ');
                    unsigned last = request[0].lastIndexOf(' ');
                    std::string url = request[0].substring(first + 1, last).c_str();
                    Serial.println(url.c_str());

                    std::map<std::string, manejadores::Manejador *>::iterator par = manejadores_.find(url);

                    if (par == manejadores_.end()) //Esto indica que la clave no esta en el diccionario
                    {
                        client.println("ERROR 404");
                    }
                    else
                    {
                        manejadores::Manejador *manejador = par->second;
                        client.println(manejador->Responder(datos).c_str());
                    }
                    client.println();
                    break;
                }
            }
        }
        // Close the connection
        client.stop();
        Serial.println("Client disconnected.");
        Serial.println("");
    }
}