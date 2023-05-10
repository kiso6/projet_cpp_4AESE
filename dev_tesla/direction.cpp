#include "direction.h"
#include "Servo.h"
#include "grove_class.h"
#include <Arduino.h>

dir::dir():Actionneur(){}

void dir::init(int pin){
  direction.attach(pin);
}
void dir::ecrire(int pos){
  direction.write(pos);
}

void dir::gauche(){
  direction.write(150);
}

void dir::droite(){
  direction.write(180);
}

void dir::tout_droit(){
  direction.write(165);
}

dir::~dir(){};
