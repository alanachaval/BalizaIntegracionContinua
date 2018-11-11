#include <Arduino.h>
#include "controlador_led.hpp"

#define GROUND 25
#define LED_ROJO 12
#define LED_VERDE 27
#define LED_AMARILLO 29 //PENDIENTE CORROBORACION

using namespace adaptadores;

ControladorLed::ControladorLed()
{
    pinMode(LED_ROJO, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);
    pinMode(GROUND, OUTPUT);
    digitalWrite(GROUND, LOW);
}

void ControladorLed::PrenderLuzRoja()
{
    digitalWrite(LED_ROJO, HIGH);
}

void ControladorLed::ApagarLuzRoja()
{
    digitalWrite(LED_ROJO, LOW);
}

void ControladorLed::PrenderLuzVerde()
{
    digitalWrite(LED_VERDE, HIGH);
}

void ControladorLed::ApagarLuzVerde()
{
    digitalWrite(LED_VERDE, LOW);
}

void ControladorLed::PrenderLuzAmarilla()
{
    digitalWrite(LED_AMARILLO, HIGH);
}

void ControladorLed::ApagarLuzAmarilla()
{
    digitalWrite(LED_AMARILLO, LOW);
}