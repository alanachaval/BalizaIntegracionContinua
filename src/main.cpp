#include <Arduino.h>
#include <WiFi.h>
#include "adaptadores/controlador_led.hpp"
#include "adaptadores/servidor_wifi.hpp"
#include "adaptadores/request_travis.hpp"
#include "adaptadores/request_travis.hpp"
#include "adaptadores/cliente_wifi.hpp"
#include "dominio/procesador.hpp"
#include "dominio/visualizador_de_estado.hpp"

using namespace adaptadores;

const char *servidor_ssid = "ESP32-Access-Point";
const char *servidor_password = "123456789";

const char *cliente_ssid = "ssid";
const char *cliente_password = "password";

ServidorWiFi *servidor_wifi;

Procesador *procesador;
ClienteWiFi *wifi;
ControladorLed *controladorLedMain;
VisualizadorDeEstado *visualizador_de_estado;
int repeticiones = 0;

void setup()
{
  Request *request = new RequestTravis("some_repo", "some_token");
  controladorLedMain = new ControladorLed();
  visualizador_de_estado = new VisualizadorDeEstado();
  visualizador_de_estado->SetControladorLed(controladorLedMain);
  procesador = new Procesador();
  procesador->SetRequest(request);
  procesador->SetVisualizadorDeEstado(visualizador_de_estado);
  servidor_wifi = new ServidorWiFi();
  Serial.begin(115200);
  delay(10000);

  Serial.print("Setting AP (Access Point)…");
  servidor_wifi->Iniciar(servidor_ssid, servidor_password);

  Serial.print("AP IP address: ");
  Serial.println(servidor_wifi->ObtenerIP());

  wifi = new ClienteWiFi();
}

void loop()
{
  if (repeticiones == 100)
  {
    if (wifi->EstaConectado())
    {
      procesador->ActualizarEstado();
    }
    else
    {
      wifi->Conectar(cliente_ssid, cliente_password);
    }
    repeticiones = 0;
  }
  if (repeticiones % 10 == 0)
  {
    servidor_wifi->AtenderCliente();
  }
  visualizador_de_estado->Actualizar(100);
  delay(100);
  repeticiones++;
}