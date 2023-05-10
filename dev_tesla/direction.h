#include <Arduino.h>
#include "Servo.h"
#include "grove_class.h"
#ifndef DIRECTION_H
#define DIRECTION_H

class dir:public Actionneur{
public:
  Servo direction;
  dir();
  void init(int pin);
  void ecrire(int pos);
  void gauche();
  void droite();
  void tout_droit();
  ~dir();

};

#endif
