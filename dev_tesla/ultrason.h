#include <Arduino.h>
#include "grove_class.h"
#ifndef ULTRASON_H
#define ULTRASON_H

class ultrason: public Capteur{
private:
    int _pin;//pin number of Arduino that is connected with SIG pin of Ultrasonic Ranger.
    long duration(uint32_t timeout = 1000000L);
public:
    ultrason();
    ultrason(int pin);
    long MeasureInCentimeters(uint32_t timeout = 1000000L);
    long MeasureInMillimeters(uint32_t timeout = 1000000L);
    long MeasureInInches(uint32_t timeout = 1000000L);
    bool Danger(long dist_cm);
};




#endif