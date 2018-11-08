#include <Arduino.h>
#include "controlador_led_built_in.hpp"

#define LED_BUILT_IN 2

using namespace adaptadores;

ControladorLedBuiltIn::ControladorLedBuiltIn()
{
    pinMode(LED_BUILT_IN, OUTPUT);
}

void ControladorLedBuiltIn::PrenderLedRojo()
{
    digitalWrite(LED_BUILT_IN, HIGH);
    Serial.println("LED Rojo prendido");
}

void ControladorLedBuiltIn::ApagarLedRojo()
{
    digitalWrite(LED_BUILT_IN, LOW);
    Serial.println("LED Rojo apagado");
}

void ControladorLedBuiltIn::PrenderLedVerde()
{
    Serial.println("LED Verde prendido");
}

void ControladorLedBuiltIn::ApagarLedVerde()
{
    Serial.println("LED Verde apagado");
}