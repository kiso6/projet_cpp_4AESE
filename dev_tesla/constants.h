#include <Arduino.h>
#ifndef CONSTANTS_H
#define CONSTANTS_H

/*Ici sont definies toutes les constantes et
pins utilisées dans la réalisation du projet. 
*/
#define DANGER_ZONE 40 //limite de la zone de danger pour l'arrêt d'urgence
#define BAUD 9600 //baudrate pour le debug
#define MOTEUR_P1 D4 // pin1 moteur 
#define MOTEUR_P2 4 //pin2 moteur 
#define DIRECTION D3 //pin servo
#define PHARE_G D5 //pin led1 (gauche)
#define PHARE_D D6 //pin led2 (droite)
#define KLAXON D7 //pin buzzer
#define ULTRASONIC D8 //pin capteur ultrason

#endif