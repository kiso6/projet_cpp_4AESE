#include "Arduino.h"
#include "grove_class.h"
#include "klaxon.h"

using namespace std;

Buzzer::Buzzer(){}
Buzzer::Buzzer(int pin,int mode):Actionneur(pin,mode){}

void Buzzer::Init(int mode){pinMode(pin1,pin1mode);}

void Buzzer::klaxonner(int duree, bool IsOn){
  if (IsOn){
    digitalWrite(pin1,HIGH);
    delay(duree);
    digitalWrite(pin1,LOW);
  }
}