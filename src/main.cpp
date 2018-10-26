#include <Arduino.h>
#include "adaptadores/controlador_led_built_in.hpp"
#include "adaptadores/request_travis.hpp"
#include "adaptadores/wifi.hpp"

using namespace adaptadores;

const char *ssid = "ssid";
const char *password = "password";

Request *request;
Wifi *wifi;
ControladorLed *controladorLed;

void setup()
{
  Serial.begin(115200);
  delay(4000);

  controladorLed = new ControladorLedBuiltIn();
  //wifi = new Wifi();
  //request = new RequestTravis();
}

void loop()
{
  /*if (wifi->estaConectado())
  {
    controladorLed->PrenderLedRojo();
    request->ObtenerEstado();
  }
  else
  {
    controladorLed->ApagarLedRojo();
    wifi->conectar(ssid, password);
  }

  delay(10000);*/
}