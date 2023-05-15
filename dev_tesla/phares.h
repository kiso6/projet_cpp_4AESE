#include "grove_class.h"
#ifndef PHARES_H
#define PHARES_H

//definition de la classe Led
class Led : public Actionneur {
public: 
  Led(); //constructeur par defaut
  Led(int pin, int mode); //constructeur paramétré
  Led(Led&); //constructeur de recopie
  void Init(int); //initialisation des pins  
  void clignotant(); //implementation du clignotant
  void phare(bool); // activation d'un mode phares
  ~Led(); //destructeur
};

#endif