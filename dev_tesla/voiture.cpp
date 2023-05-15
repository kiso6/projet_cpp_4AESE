#include "grove_class.h"
#include "phares.h"
#include "klaxon.h"
#include "motor.h"
#include "voiture.h"
#include "constants.h"
#include <Servo.h>
//#include "Ultrasonic.h"
#include "ultrason.h"
#include "direction.h"
#include <Arduino.h>


/*Implementation de la classe voiturette*/
Voiturette::Voiturette(){
  direction.init(DIRECTION);
  PhG.Init(OUTPUT);
  PhD.Init(OUTPUT);
  Klax.Init(OUTPUT);
  Moteur.init_digital();
}

Voiturette::~Voiturette(){}
