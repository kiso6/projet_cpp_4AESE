#include "Arduino.h"
#include "grove_class.h"
#include "phares.h"

using namespace std;

//LED DEFINE
Led::Led(){}
Led::Led(int pin,int mode):Actionneur(pin,mode){}
Led::Led(Led& Ld):Actionneur(Ld.pin1,Ld.pin1mode){}
void Led::Init(int mode){pinMode(pin1,pin1mode);}

void Led::clignotant(){
  digitalWrite(pin1,!digitalRead(pin1));

}

void Led::phare(bool IsOn){
  digitalWrite(pin1,IsOn);
}