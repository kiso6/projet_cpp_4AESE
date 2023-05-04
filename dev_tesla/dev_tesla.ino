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


bool left;
bool right;
bool gaz;
bool brake;
bool warning;
bool klaxon;
//-----------

Voiturette* meccano=new Voiturette();

Ticker clignoG;
Ticker clignoD;
bool clignoG_on;
bool clignoD_on;
long RangeInCentimeters;
int pos;

// void rotate_left(int angle, Servo out){
//   out.write(-angle);
// }

// void rotate_right(int angle, Servo out){
//   out.write(+angle);
// }

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

void setup()
{
  Serial.begin(BAUD);
  pos =170;
  meccano->direction.write(pos);

  //wifi intit
  WiFi.softAP(ssid);
  IPAddress myIP = WiFi.softAPIP();
  Udp.begin(localUdpPort);

  Serial.print("AP IP address: ");
  Serial.println(myIP);

  clignoG.attach(0.2, clignoterG);
  clignoD.attach(0.2, clignoterD);

}

void loop()
{
  int packetSize = Udp.parsePacket();
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

      if (gaz == 1){
        meccano->Moteur.avant();
      }
      else if (brake == 1){
        meccano->Moteur.arriere();
      }
      else {
        meccano->Moteur.stop();
      }

      if (left == 1){
        meccano->direction.write(150);
        clignoD_on = warning;
        clignoG_on = 1;
      }
      else if (right == 1){
        meccano->direction.write(180);
        clignoG_on = warning;
        clignoD_on = 1;
      }
      else {
        meccano->direction.write(165);
        clignoG_on = warning;
        clignoD_on = warning;
      }
      meccano->Klax.klaxonner(klaxon);
    }
  }


  RangeInCentimeters=meccano->detect.MeasureInCentimeters();
  Serial.println(String(RangeInCentimeters));





}