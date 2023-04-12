#include "grove_class.h"
#ifndef PHARES_H
#define PHARES_H

class Led : public Actionneur {
public: 
  Led();
  Led(int pin, int mode);
  void Init(int);
  void clignotant(int);
  void phare(bool);
};

#endif