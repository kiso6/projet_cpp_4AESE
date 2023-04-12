#include "Ultrasonic.h"
#include "constants.h"
#include "grove_class.h"
#include "phares.h"
#include "klaxon.h"
#include <Servo.h>
#include <String>

Servo direction;
Ultrasonic ultrasonic(ULTRASONIC);
Led Phare_Gauche(PHARE_G,OUTPUT);
Led Phare_Droit(PHARE_D,OUTPUT);
Buzzer Klaxon(KLAXON, OUTPUT);

bool Phare_D=false;
bool Phare_G=false;
bool Klax=false;
long RangeInCentimeters;
int pos =0;

void printDist(long dist){
  
}

void rotate_left(int angle, Servo out){
  out.write(-angle);
}

void rotate_right(int angle, Servo out){
  out.write(+angle);
}

void setup()
{
 direction.attach(DIRECTION);
 direction.write(pos);
 Serial.begin(BAUD);
 Phare_Gauche.Init(OUTPUT);
 Phare_Droit.Init(OUTPUT);
 Klaxon.Init(OUTPUT);
}

void loop()
{
 Phare_G=true;
 Phare_D=true;
 Phare_Droit.clignotant(150);
 delay(100);
 Phare_Gauche.clignotant(2000);

 for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    direction.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    direction.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  RangeInCentimeters=ultrasonic.MeasureInCentimeters();
  String distance_cm=String(RangeInCentimeters);
  Serial.print(distance_cm);//0~400cm
  Serial.println(" cm");

  delay(100);
  Klax=true;
  Klaxon.klaxonner(100, Klax);
  Klax=false;
}