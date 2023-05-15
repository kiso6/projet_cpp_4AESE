#include "constants.h"
#include "grove_class.h"
#include "phares.h"
#include "klaxon.h"
#include "motor.h"
#include "ultrason.h"
#include "direction.h"
#include "voiture.h"
//#include <Servo.h>
#include <String>
#include <Ticker.h>

//wifi configuration
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>

#ifndef APSSID
#define APSSID "Voiture"
#endif

WiFiUDP Udp;
unsigned int localUdpPort = 4210;
char incomingPacket[256];

const char *ssid = APSSID;

//Initialisation des booleens utilisés dans le programme principal
bool left; //tourne à gauche + cligno gauche si == true
bool right;//tourne à droite + cligno droite si == true
bool gaz;//accelere si == true
bool brake;//recule si == true
bool warning;//active le mode warning si == true
bool klaxon;//klaxonne si == true
bool danger=false;//empeche l'acdeleration si == true

//------------------------------------------------

//declaration de l'instance de voiturette utilisée dans le programme principal
Voiturette* meccano=new Voiturette();

//setup des tickers pour faire fonctionner les clignotants en simultané si besoin
Ticker clignoG;
Ticker clignoD;
bool clignoG_on;
bool clignoD_on;

//init des variables pour l'acquisition de position
long RangeInCentimeters; //valeur mesurée à chaque tour de boucle
int pos;

//declaration des fonctions d'interruption pour les clignotants
void clignoterG() {
  if (clignoG_on == 1) {
    meccano->PhG.clignotant();
  }
  else {
    meccano->PhG.phare(0);
  }
}

void clignoterD() {
  if (clignoD_on == 1) {
    meccano->PhD.clignotant();
  }
  else {
    meccano->PhD.phare(0);
  }
}

//-----------------------------------------

void setup()
{
  //init du baudrate pour la communication sérial (utilisé que pour le débug)
  Serial.begin(BAUD);

  //wifi intit
  WiFi.softAP(ssid);
  IPAddress myIP = WiFi.softAPIP();
  Udp.begin(localUdpPort);
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  //attribution des tickers aux clignotants
  clignoG.attach(0.2, clignoterG);
  clignoD.attach(0.2, clignoterD);

}

void loop()
{
  int packetSize = Udp.parsePacket();

  RangeInCentimeters=meccano->detect.MeasureInCentimeters();
  Serial.println(String(RangeInCentimeters));
  if (RangeInCentimeters<=DANGER_ZONE & RangeInCentimeters!=0){
        danger=true;
        meccano->Moteur.arriere();
        delay(100);
        meccano->Moteur.stop();
  }else{
    danger=false;
  }

  
  if (gaz ==1 & !danger){
    meccano->Moteur.stop();
    meccano->Moteur.avant();
  }
  else if (brake == 1){
    meccano->Moteur.stop();
    meccano->Moteur.arriere();
  }
  else {
    meccano->Moteur.stop();
  }

  if (packetSize)
  {
    int len = Udp.read(incomingPacket, 255);
    if (len > 0)
    {
      incomingPacket[len] = '\0';
      
      left = incomingPacket[0] - 48;
      right = incomingPacket[1] - 48;
      gaz = incomingPacket[2] - 48;
      brake = incomingPacket[3] - 48;
      warning = incomingPacket[4] - 48;
      klaxon = incomingPacket[5] - 48;

      if (left == 1){
        meccano->direction.gauche();
        clignoD_on = warning;
        clignoG_on = 1;
      }
      else if (right == 1){
        meccano->direction.droite();
        clignoG_on = warning;
        clignoD_on = 1;
      }
      else {
        meccano->direction.tout_droit();
        clignoG_on = warning;
        clignoD_on = warning;
      }
      meccano->Klax.klaxonner(klaxon);
    }
  }


}