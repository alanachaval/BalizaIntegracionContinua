#include <Arduino.h>
#include "controlador_led.hpp"

#define LED_ROJO 4
#define LED_VERDE 19
#define LED_AMARILLO 5

using namespace adaptadores;

ControladorLed::ControladorLed()
{
    pinMode(LED_ROJO, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_AMARILLO, OUTPUT);
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