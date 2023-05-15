#include "grove_class.h"
#ifndef MOTOR_H
#define MOTOR_H

//definition de la classe moteur
class motor: public Actionneur{
public:
  motor(); //constrcteur par défaut
  motor(int pin1,int pin1mode); //constructeur paramétré 1
  motor(int pin1,int pin1mode,int pin2, int pin2mode); //constructeur paramétré 2
  motor(motor&); //constructeur de recopie 
  void init_digital(); //init des pins
  void avant(); //marche avt
  void arriere(); //marche arr 
  void stop(); // arrêt du moteur
  ~motor(); //destructeur
};




#endif