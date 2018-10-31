#include <Arduino.h>
#include "controlador_led.hpp"

#define GROUND 25
#define LED_ROJO 12
#define LED_VERDE 27

using namespace adaptadores;

ControladorLed::ControladorLed()
{
    pinMode(LED_ROJO, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);
    pinMode(GROUND, OUTPUT);
    digitalWrite(GROUND, LOW);
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