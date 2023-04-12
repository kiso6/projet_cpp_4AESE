//192.168.4.1

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>

#ifndef APSSID
#define APSSID "ESPap"
#define APPSK "thereisnospoon"
#endif

WiFiUDP Udp;
unsigned int localUdpPort = 4210;
char incomingPacket[256];


/* Set these to your desired credentials. */
const char *ssid = APSSID;
const char *password = APPSK;

bool left;
bool right;
bool gaz;
bool warning;
bool klaxon;



void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  Udp.begin(localUdpPort);


}

void loop() {
  int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(incomingPacket, 255);
    if (len > 0)
    {
      incomingPacket[len] = '\0';
    }
    Serial.printf("UDP packet contents: %s\n", incomingPacket);
    
    left = incomingPacket[0] - 48;
    right = incomingPacket[1] - 48;
    gaz = incomingPacket[2] - 48;
    warning = incomingPacket[3] - 48;
    klaxon = incomingPacket[4] - 48;

    Serial.println(left);
    Serial.println(right);
    Serial.println(gaz);
    Serial.println(warning);
    Serial.println(klaxon);
  }
}
