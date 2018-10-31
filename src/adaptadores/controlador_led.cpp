#include <Arduino.h>
#include "controlador_led_built_in.hpp"

#define LED_ROJO 2
#define LED_VERDE 3

using namespace adaptadores;

ControladorLed::ControladorLed()
{
    pinMode(LED_ROJO, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);
}

void ControladorLed::PrenderLedRojo()
{
    digitalWrite(LED_ROJO, HIGH);
    Serial.println("LED Rojo prendido");
}

void ControladorLed::ApagarLedRojo()
{
    digitalWrite(LED_ROJO, LOW);
    Serial.println("LED Rojo apagado");
}

void ControladorLed::PrenderLedVerde() {
    digitalWrite(LED_VERDE, HIGH);
    Serial.println("LED Verde prendido");
}

void ControladorLed::ApagarLedVerde() {
    digitalWrite(LED_VERDE, LOW);
    Serial.println("LED Verde apagado");
}