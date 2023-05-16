#include "grove_class.h"
#include <Arduino.h>
using namespace std;

//GROVE DEFINE
Grove::Grove(){}
Grove::Grove(int p1,int p1m):pin1{p1},pin1mode{p1m}{}
Grove::Grove(int p1,int p1m,int p2,int p2m):pin1{p1},pin1mode{p1m},pin2{p2},pin2mode{p2m}{}
Grove& Grove::operator=(const Grove& G){
  pin1=G.pin1;
  pin2=G.pin2;
  pin1mode=G.pin1mode;
  pin2mode=G.pin2mode;
  return *this;
}
Grove::~Grove(){}

//CAPTEURS DEFINE
Capteur::Capteur():Grove(){}
Capteur::Capteur(int p1, int p1m):Grove(p1,p1m){}
Capteur::Capteur(int p1, int p1m,int p2,int p2m):Grove(p1,p1m,p2,p2m){}
Capteur::~Capteur(){}

//ACTIONNEURS DEFINE
Actionneur::Actionneur():Grove(){}
Actionneur::Actionneur(int p1,int p1m):Grove(p1,p1m){}
Actionneur::Actionneur(int p1,int p1m,int p2,int p2m):Grove(p1,p1m,p2,p2m){}
Actionneur::~Actionneur(){}

