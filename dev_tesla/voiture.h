#include "grove_class.h"
#include "phares.h"
#include "klaxon.h"
#include "motor.h"
#include "Ultrasonic.h"
#include "constants.h"
#include <Servo.h>
#include <Arduino.h>
#ifndef VOITURE_H
#define VOITURE_H

class Voiturette{
public: 
  motor Moteur=motor(MOTEUR_P1,OUTPUT,MOTEUR_P2,OUTPUT);
  Led PhD=Led(PHARE_D,OUTPUT);
  Led PhG=Led(PHARE_G,OUTPUT);
  Buzzer Klax=Buzzer(KLAXON,OUTPUT);
  Ultrasonic detect=Ultrasonic(ULTRASONIC);
  Servo direction;
  Voiturette();
  ~Voiturette();
};



#endif