#include <Arduino.h>
#include <WiFi.h>
#include "adaptadores/controlador_led.hpp"
#include "adaptadores/servidor_wifi.hpp"
#include "adaptadores/cliente_wifi.hpp"
#include "dominio/procesador.hpp"
#include "dominio/visualizador_de_estado.hpp"

using namespace adaptadores;

const char *servidor_ssid = "ESP32-Access-Point";
const char *servidor_password = "123456789";

ServidorWiFi *servidor_wifi;
Procesador *procesador;
ClienteWiFi *cliente_wifi;
ControladorLuz *controlador_luz;
VisualizadorDeEstado *visualizador_de_estado;
int repeticiones = 0;
unsigned long milisegundos_ultima_ejecucion = 0UL;

void setup()
{
  controlador_luz = new ControladorLed();
  visualizador_de_estado = new VisualizadorDeEstado();
  visualizador_de_estado->SetControladorLuz(controlador_luz);
  procesador = new Procesador();
  procesador->SetVisualizadorDeEstado(visualizador_de_estado);
  cliente_wifi = new ClienteWiFi();
  servidor_wifi = new ServidorWiFi(procesador, cliente_wifi);
  Serial.begin(115200);
  delay(10000);

  Serial.print("Setting AP (Access Point)…");
  servidor_wifi->Iniciar(servidor_ssid, servidor_password);

  Serial.print("AP IP address: ");
  Serial.println(servidor_wifi->ObtenerIP());

  milisegundos_ultima_ejecucion = millis();
}

void loop()
{
  if (repeticiones % 10 == 0)
  {
    servidor_wifi->AtenderCliente();
  }
  if (repeticiones == 50)
  {
    if (cliente_wifi->EstaConectado())
    {
      procesador->ActualizarEstado();
    }
    else
    {
      visualizador_de_estado->SetEstadoDelBuild(kEstadoDesconectado);
      cliente_wifi->Reconectar();
    }
    repeticiones = 0;
  }
  unsigned long milisegundos = millis();
  unsigned long milisegundos_repeticion = milisegundos - milisegundos_ultima_ejecucion;
  milisegundos_ultima_ejecucion = milisegundos;
  visualizador_de_estado->Actualizar(milisegundos_repeticion);
  delay(100);
  repeticiones++;
}