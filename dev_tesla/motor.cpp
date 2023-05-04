#include <Arduino.h>
#include "grove_class.h"
#include "motor.h"
using namespace std;

motor::motor(){}
motor::motor(int pin1, int pin1mode, int pin2, int pin2mode):Actionneur(pin1, pin1mode, pin2,pin2mode){}
motor::motor(motor& mot):Actionneur(mot.pin1, mot.pin1mode, mot.pin2,mot.pin2mode){}
motor::motor(int pin1,int pin1mode):Actionneur(pin1, pin1mode){};

void motor::init_digital(){
  pinMode(pin1, pin1mode);
  pinMode(pin2, pin2mode);
  digitalWrite(pin1,0);
  digitalWrite(pin2,0);
}

void motor::avant(){
  digitalWrite(pin1, 1);
  digitalWrite(pin2, 0);
}

void motor::arriere(){
  digitalWrite(pin2, 1);
  digitalWrite(pin1, 0);
}

void motor::stop(){
  digitalWrite(pin1, 0);
  digitalWrite(pin2, 0);
}

motor::~motor(){}