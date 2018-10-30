#include <Arduino.h>
#include <WiFi.h>
#include "adaptadores/controlador_led_built_in.hpp"
#include "adaptadores/servidor_wifi.hpp"
#include "adaptadores/request_travis.hpp"
#include "adaptadores/request_travis.hpp"
#include "adaptadores/cliente_wifi.hpp"

using namespace adaptadores;

//const char *ssid = "ESP32-Access-Point";
//const char *password = "123456789";

const char *ssid = "ssid";
const char *password = "password";

//ServidorWiFi *servidor_wifi;

Request *request;
ClienteWiFi *wifi;
ControladorLed *controladorLedMain;

void setup()
{
  //servidor_wifi = new ServidorWiFi();
  request = new RequestTravis("some_repo", "some_token");
  Serial.begin(115200);

  //Serial.print("Setting AP (Access Point)…");
  //servidor_wifi->Iniciar(ssid, password);

  //Serial.print("AP IP address: ");
  //Serial.println(servidor_wifi->ObtenerIP());

  controladorLedMain = new ControladorLedBuiltIn();
  wifi = new ClienteWiFi();
  //request = new RequestTravis();
}

void loop()
{
  EstadoDelBuild estado = kEstadoDesconocido;
  if (wifi->EstaConectado())
  {
    controladorLedMain->PrenderLedRojo();
    estado = request->ObtenerEstado();
  }
  else
  {
    controladorLedMain->ApagarLedRojo();
    wifi->Conectar(ssid, password);
  }
  
  delay(10000);
  //servidor_wifi->AtenderCliente();
}