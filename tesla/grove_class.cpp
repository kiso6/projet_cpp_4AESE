#include "grove_class.h"


=======
#include <Arduino.h>
using namespace std;

//GROVE DEFINE
Grove::Grove(int p1,int p1m):pin1{p1},pin1mode{p1m}{}
Grove::Grove(int p1,int p1m,int p2,int p2m):pin1{p1},pin1mode{p1m},pin2{p2},pin2mode{p2m}{}



//ACTIONNEURS DEFINE
Actionneur::Actionneur(int p1,int p1m):Grove(p1,p1m){}
Actionneur::Actionneur(int p1,int p1m,int p2,int p2m):Grove(p1,p1m,p2,p2m){}

//LED DEFINE
Led::Led(int pin,int mode):Actionneur(pin,mode){}
void Led::Init(int mode){pinMode(pin1,pin1mode);}

void Led::clignotant(int period){
    digitalWrite(pin1,HIGH);
    delay(period);
    digitalWrite(pin1,LOW);
    delay(period);
}

void Led::phare(bool IsOn){
    if (IsOn){
        digitalWrite(pin1,HIGH);
    }
}

Buzzer::Buzzer(int pin,int mode):Actionneur(pin,mode){}
void Buzzer::Init(int mode){pinMode(pin1,pin1mode);}
void Buzzer::klaxonner(int duree, bool IsOn){
  if (IsOn){
    digitalWrite(pin1,HIGH);
    delay(duree);
    digitalWrite(pin1,LOW);
  }
}
