#include <Arduino.h>
#include "controlador_led_rojo_verde.hpp"

#define GROUND 25
#define LED_ROJO 12
#define LED_VERDE 27

using namespace adaptadores;

ControladorLedRojoVerde::ControladorLedRojoVerde()
{
    pinMode(LED_ROJO, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);
    pinMode(GROUND, OUTPUT);
    digitalWrite(GROUND, LOW);
}

void ControladorLedRojoVerde::PrenderLedRojo()
{
    digitalWrite(LED_ROJO, HIGH);
}

void ControladorLedRojoVerde::ApagarLedRojo()
{
    digitalWrite(LED_ROJO, LOW);
}

void ControladorLedRojoVerde::PrenderLedVerde()
{
    digitalWrite(LED_VERDE, HIGH);
}

void ControladorLedRojoVerde::ApagarLedVerde()
{
    digitalWrite(LED_VERDE, LOW);
}