# projet_cpp_4AESE
## Projet de C++ de 4AESE: _Voiturette télécommandée_  

_Raphael Tessier et Kilian Soual_

**_[ATTENTION] Image pas forcément contractuelle :_**  
![Image pas forcemment contractuelle](https://i.gaw.to/vehicles/photos/40/25/402549-2021-tesla-model-x.jpg?640x400)  

## Sommaire:  
  1.[Description](https://github.com/kiso6/projet_cpp_4AESE#description)  
  2.[Specifications](https://github.com/kiso6/projet_cpp_4AESE#specifications)  
  3.[Hardware](https://github.com/kiso6/projet_cpp_4AESE#hardware)  
  4.[Software](https://github.com/kiso6/projet_cpp_4AESE#software)  
  5.[UML Description](https://github.com/kiso6/projet_cpp_4AESE#uml-description)  
      5.1.[Diagramme des uses cases](https://github.com/kiso6/projet_cpp_4AESE#use-cases)  
      5.2.[Diagrammes de séquences](https://github.com/kiso6/projet_cpp_4AESE#diagrammes-de-s%C3%A9quence)  
      5.3.[Diagrammes des classes](https://github.com/kiso6/projet_cpp_4AESE#diagramme-des-classes)  
    
  
## Description:  
Le projet consiste en la réalisation d'une voiturette télécommandée (via une application mobile). Le projet est porté par une carte ESP266 et la communication avec la télécommande se fait en WiFi. Le code embarqué est en C++ et l'application mobile à été réalisée avec le MIT App Inventor. La structure de la voiturette est entièrement réalisée en Meccano.  
  

## Specifications:  
**Board**: ESP8266 + Shield Grove  
**Language**: C++ 17  
**PINOUT :**  
![Pinout](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/05/ESP8266-NodeMCU-kit-12-E-pinout-gpio-pin.png?quality=100&strip=all&ssl=1)  

## Hardware:  
**Matériel** :  
[LINK](https://www.seeedstudio.com/ "Grove Actuators/Sensors")
  - Moteur DC 6V de voiturette Meccano  
  - Deux relais pour faire de la marche avant et de la marche arrière
  - Servomoteur x1 pour la direction
  - 2 leds (jaune x2) pour les phares/clignotants
  - capteur ultrason pour la detection d'obstacles
  - strcuture Meccano
  
## Software
  - cf. /dev_tesla pour voir le code embarqué [CODE EMBARQUE](https://github.com/kiso6/projet_cpp_4AESE/tree/main/dev_tesla)
  - cf. /appli pour voir le code de l'appli APK [APPLI APK](https://github.com/kiso6/projet_cpp_4AESE/tree/main/appli)
  
## UML Description
### Use cases
![user case](https://user-images.githubusercontent.com/128903240/235663121-4138d28a-abcd-4ec0-8b22-39a8af73595d.png)  
### Diagrammes de séquence  
Ici, nous illustrons deux cas d'utilisation classiques: le cas où l'utilisateur utilise la voiturette en utilisant l'application (1), et le cas ou la voiturette détecte un danger(2).  
#### Diagramme 1  
![séquence_1](https://i.ibb.co/rGPwkZM/Diagramme-s-quence-g-n.png)  
#### Diagramme 2  
![séquence_2](https://i.ibb.co/cTNppyq/DIAGRAMME-seq-ultrasonic.png)  
### Diagramme des classes
![diagramme_classes_global](https://i.ibb.co/Tq1Vfgr/Diagramme-Classes-1.png)
### Diagramme des classes de la Voiturette  
![diagramme_classes_2](https://i.ibb.co/9hqwd1P/Diagramme-Classes-2.png)

