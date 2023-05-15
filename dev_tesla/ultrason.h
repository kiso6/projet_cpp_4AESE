#include <Arduino.h>
#include "grove_class.h"
#ifndef ULTRASON_H
#define ULTRASON_H

/*********** LES FONCTIONS POUR LE CAPTEUR ULTRASON
SONT ISSUES DE LA LIBRAIRIE ULTRASONIC.H (disponible dans le fichier source du projet) 
TROUVEES SUR LE SITE www.seeed.cc ||
ICI ELLES SONT UTILISEES/ENCAPSULEES DANS UNE CLASSE DEFINIE PAR NOS SOINS.
************/
class ultrason: public Capteur{
private:
    int _pin;
    long duration(uint32_t timeout = 1000000L);
public:
    ultrason();
    ultrason(int pin);
    long MeasureInCentimeters(uint32_t timeout = 1000000L);
    bool Danger(long dist_cm);
};




#endif