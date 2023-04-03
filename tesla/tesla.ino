#include "grove_class.h"
#include "constants.h"
using namespace std;
//const int led_gauche=D5;
//const int led_droite=D6;

Led Phare_Gauche(PHARE_G,OUTPUT);
Led Phare_Droit(PHARE_D,OUTPUT);
Buzzer Klaxon(KLAXON, OUTPUT);


void setup() {
 Phare_Gauche.Init(OUTPUT);
 Phare_Droit.Init(OUTPUT);
 Klaxon.Init(OUTPUT);
}

bool Phare_D=false;
bool Phare_G=false;
bool Klax=false;

void loop() {
  Phare_G=true;
  Phare_Gauche.phare(Phare_G);
  delay(1500);
  Phare_D=true;
  Phare_Droit.phare(Phare_D);
  delay(1500);
  Klax=true;
  Klaxon.klaxonner(100, Klax);
  Klax=false;
}