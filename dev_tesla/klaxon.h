#include "grove_class.h"
#ifndef KLAXON_H
#define KLAXON_H

class Buzzer: public Actionneur{
public:
  Buzzer();
  Buzzer(int pin, int mode);
  Buzzer(Buzzer&);
  void Init(int);
  void klaxonner(int,bool);
};

#endif