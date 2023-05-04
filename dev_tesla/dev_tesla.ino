#include "constants.h"
#include "grove_class.h"
#include "phares.h"
#include "klaxon.h"
#include "motor.h"
#include "voiture.h"

#include "Ultrasonic.h"
#include <Servo.h>
#include <String>
#include <Ticker.h>
//Servo direction;
//Ticker cligno;
/*
Ultrasonic ultrasonic(ULTRASONIC);
Led Phare_Gauche(PHARE_G,OUTPUT);
Led Phare_Droit(PHARE_D,OUTPUT);
Buzzer Klaxon(KLAXON, OUTPUT);
motor moteur(MOTEUR_P1,OUTPUT,MOTEUR_P2,OUTPUT); 
*/
Voiturette* meccano=new Voiturette();

bool Phare_D=false;
bool Phare_G=false;
long RangeInCentimeters;
int pos;

void rotate_left(int angle, Servo out){
  out.write(-angle);
}

void rotate_right(int angle, Servo out){
  out.write(+angle);
}

void setup()
{
 pos =170;
 meccano->direction.write(pos);
 Serial.begin(BAUD);
}

void loop()
{
 meccano->Moteur.avant();
 delay(2000);
 meccano->Moteur.arriere();
 delay(2000);
 meccano->Moteur.stop();
 delay(2000);
 meccano->PhD.clignotant(150);
 meccano->PhG.clignotant(150);
 delay(2000);
 RangeInCentimeters=meccano->detect.MeasureInCentimeters();
 Serial.print(String(RangeInCentimeters));
 delay(2000);
 for (pos = 150; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    meccano->direction.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 180; pos >= 160; pos -= 1) { // goes from 180 degrees to 0 degrees
    meccano->direction.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

 
 /*Phare_G=true;
 Phare_D=true;
 Phare_Droit.clignotant(150);
 delay(100);
 Phare_Gauche.clignotant(2000);

 for (pos = 150; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    //direction.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 180; pos >= 160; pos -= 1) { // goes from 180 degrees to 0 degrees
    //direction.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  RangeInCentimeters=ultrasonic.MeasureInCentimeters();
  String distance_cm=String(RangeInCentimeters);
  Serial.print(distance_cm);//0~400cm
  Serial.println(" cm");

  //delay(100);
  //Klax=true;
  //Klaxon.klaxonner(100, Klax);
  //Klax=false;

  /*
  moteur.stop();
  delay(2000);
  moteur.avant();
  delay(2000);
  moteur.stop();
  delay(2000);
  moteur.arriere();
  delay(2000);
  moteur.stop();
  delay(2000);*/

}