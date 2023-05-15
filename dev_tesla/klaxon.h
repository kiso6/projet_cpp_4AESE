#include "grove_class.h"
#ifndef KLAXON_H
#define KLAXON_H

//definition de la classe buzzer
class Buzzer: public Actionneur{
public:
  Buzzer(); //constructeur par defaut
  Buzzer(int pin, int mode);//constructeur paramétré 
  Buzzer(Buzzer&);//constructeur de recopie
  void Init(int); //initialisation des pins
  void klaxonner(bool); //fonction permettant de klaxonner
  ~Buzzer(); //destructeur 
};

#endif