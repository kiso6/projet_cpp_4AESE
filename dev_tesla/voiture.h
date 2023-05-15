#include "grove_class.h"
#include "phares.h"
#include "klaxon.h"
#include "motor.h"
//#include "Ultrasonic.h"
#include "ultrason.h"
#include "direction.h"
#include "constants.h"
#include <Servo.h>
#include <Arduino.h>
#ifndef VOITURE_H
#define VOITURE_H


/* définition de la classe voiturette qui est utlisée uniquement dans le main 
cette classe n'a pour but que de proposer une interface pour simplifier le main et le rendre plus lisible.
La protection des attributs n'est donc pas nécessaire.
*/
class Voiturette{
public: 
  motor Moteur=motor(MOTEUR_P1,OUTPUT,MOTEUR_P2,OUTPUT);
  Led PhD=Led(PHARE_D,OUTPUT);
  Led PhG=Led(PHARE_G,OUTPUT);
  Buzzer Klax=Buzzer(KLAXON,OUTPUT);
  ultrason detect=ultrason(ULTRASONIC);
  dir direction;
  Voiturette();
  ~Voiturette();
};



#endif