#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"
#include "ultrason.h"


/*********** LES FONCTIONS POUR LE CAPTEUR ULTRASON
SONT ISSUES DE LA LIBRAIRIE ULTRASONIC.H (disponible dans le fichier source du projet) 
TROUVEES SUR LE SITE www.seeed.cc || 
ICI ELLES SONT UTILISEES/ENCAPSULEES DANS UNE CLASSE DEFINIE PAR NOS SOINS.
************/
#ifdef ARDUINO_ARCH_STM32F4

static uint32_t MicrosDiff(uint32_t begin, uint32_t end) {
    return end - begin;
}

static uint32_t pulseIn(uint32_t pin, uint32_t state, uint32_t timeout = 1000000L) {
    uint32_t begin = micros();

    // wait for any previous pulse to end
    while (digitalRead(pin)) if (MicrosDiff(begin, micros()) >= timeout) {
            return 0;
        }

    // wait for the pulse to start
    while (!digitalRead(pin)) if (MicrosDiff(begin, micros()) >= timeout) {
            return 0;
        }
    uint32_t pulseBegin = micros();

    // wait for the pulse to stop
    while (digitalRead(pin)) if (MicrosDiff(begin, micros()) >= timeout) {
            return 0;
        }
    uint32_t pulseEnd = micros();

    return MicrosDiff(pulseBegin, pulseEnd);
}

#endif // ARDUINO_ARCH_STM32F4

ultrason::ultrason():Capteur(){}

ultrason::ultrason(int pin):Capteur(pin,INPUT){
    _pin = pin;
}

long ultrason::duration(uint32_t timeout) {
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(_pin, HIGH);
    delayMicroseconds(5);
    digitalWrite(_pin, LOW);
    pinMode(_pin, INPUT);
    long duration;
    duration = pulseIn(_pin, HIGH, timeout);
    return duration;
}

// Mesure la distance en centimètres avec une portée de 0 à 400 cm
long ultrason::MeasureInCentimeters(uint32_t timeout) {
    long RangeInCentimeters;
    RangeInCentimeters = duration(timeout) / 29 / 2;
    return RangeInCentimeters;
}