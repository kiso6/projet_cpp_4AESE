#include <Arduino.h>
#include "Servo.h"
#include "grove_class.h"
#ifndef DIRECTION_H
#define DIRECTION_H

//definition de la classe dir
class dir:public Actionneur{
public:
  Servo direction;
  dir(); //constructeur par defaut
  void init(int pin); //init des pin == appel de la fonction attach, de la lib Servo
  void ecrire(int pos); //permet d'ecrire dans le servo 
  void gauche(); // permet de tourner à gauche
  void droite(); // permet de tourner à droite 
  void tout_droit(); //assure la marche avant
  ~dir(); // destructeur

};

#endif
