#include "grove_class.h"
#include "phares.h"
#include "klaxon.h"
#include "motor.h"
#include "voiture.h"
#include "constants.h"
#include <Servo.h>
#include "Ultrasonic.h"
#include <Arduino.h>

Voiturette::Voiturette(){
  direction.attach(DIRECTION);
  PhG.Init(OUTPUT);
  PhD.Init(OUTPUT);
  Klax.Init(OUTPUT);
  Moteur.init_digital();
  
}
