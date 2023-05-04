#include "grove_class.h"
#ifndef MOTOR_H
#define MOTOR_H

class motor: public Actionneur{
public:
  motor();
  motor(int pin1,int pin1mode);
  motor(int pin1,int pin1mode,int pin2, int pin2mode);
  motor(motor&);
  void init_digital();
  void avant();
  void arriere();
  void stop();
  ~motor();
};




#endif