#include "grove_class.h"
#ifndef PHARES_H
#define PHARES_H

//implementation de la classe Led
class Led : public Actionneur {
public: 
  Led();
  Led(int pin, int mode);
  Led(Led&);
  void Init(int);
  void clignotant();
  void phare(bool);
  ~Led();
};

#endif