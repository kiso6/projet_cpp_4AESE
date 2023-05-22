# RAPPORT
## _Projet de C++ de 4ème année AE - SE: Voiturette télécommandée_  

_Raphael Tessier et Kilian Soual_   

![Image pas forcemment contractuelle](https://i.ibb.co/GcdSxjs/20230510-180536.jpg)  

## SOMMAIRE  
   
1. [CONTEXTE](https://github.com/kiso6/projet_cpp_4AESE#contexte)    
2. [HARDWARE](https://github.com/kiso6/projet_cpp_4AESE#hardware)  
3. [DESCRIPTION DE L'ARCHITECTURE PHYSIQUE DU SYSTEME](https://github.com/kiso6/projet_cpp_4AESE#description-de-larchitecture-physique-du-systeme)  
4. [SOFTWARE](https://github.com/kiso6/projet_cpp_4AESE#software)       
5. [DESCRIPTION UML](https://github.com/kiso6/projet_cpp_4AESE#description-uml)    
  1 [Diagramme des uses cases](https://github.com/kiso6/projet_cpp_4AESE#use-cases)    
  2 [Diagrammes de séquences](https://github.com/kiso6/projet_cpp_4AESE#diagrammes-de-s%C3%A9quence)    
  3 [Diagrammes des classes](https://github.com/kiso6/projet_cpp_4AESE#diagramme-des-classes)   
7. [DEMONSTRATION VIDEO](https://github.com/kiso6/projet_cpp_4AESE#demonstration-video)  
8. [CONCLUSION ET PERSPECTIVES D'AMELIORATION](https://github.com/kiso6/projet_cpp_4AESE#conclusion-et-perspectives-damelioration)     
 
  
## CONTEXTE:  
Le but de ce projet est d’utiliser les capteurs et actionneurs de la gamme “Grove”, ainsi qu’une carte ESP8266 pour concevoir un produit dans l’internet des objets (IoT).
L’avantage majeur de la carte ESP8266 est qu’elle dispose d’une carte WiFi, ce qui nous permet de communiquer de manière distante avec elle.
Nous avons donc décidé de mettre au point une voiturette pilotable via une **application mobile (android)** qui utilise cette propriété de la carte. 

## HARDWARE    
  - Moteur DC 6V de voiturette Meccano  
  - Deux relais pour faire de la marche avant et de la marche arrière
  - Servomoteur x1 pour la direction [(Grove sensors)](https://www.seeedstudio.com/ "Grove Actuators/Sensors")
  - 2 leds (jaune x2) pour les phares/clignotants 
  - capteur ultrason pour la detection d'obstacles [(Grove sensors)](https://www.seeedstudio.com/ "Grove Actuators/Sensors")
  - strcuture Meccano  
  - Batterie externe pour pouvoir embarquer le système  

## DESCRIPTION DE L'ARCHITECTURE PHYSIQUE DU SYSTEME
Le système est piloté par une application qui communique avec le module WiFi de l'ESP8266. La direction est assurée par un servomoteur, placé au niveau du train avant du véhicule. Ce dernier peut pivoter à droite, à gauche, ou rester au centre en envoyant respectivement des angles de consignes de 180,150 et 165 degrés.  
La propulsion est assurée par un système de relais qui pilote un moteur DC Meccano (alimenté par des piles). Ce montage nous permet de faire à la fois de la marche avant et de la marche arrière, sans récupération d'énergie.  
Le capteur à ultrason nous permet de faire de la detection d'obstacles en face du véhicule et de forcer une marche arrière puis un freinage, afin d'éviter ce dernier. La distance dite "critique" est régulée à 40cm pour tenir compte de l'inertie du système et des délais de communication, ce qui fait que ce dernier s'arrête 25cm avant l'obstacle
  
## SOFTWARE
  - cf. /dev_tesla pour voir le code embarqué [CODE EMBARQUE](https://github.com/kiso6/projet_cpp_4AESE/tree/main/dev_tesla)
  - cf. /appli pour voir le code de l'appli APK [APPLI APK](https://github.com/kiso6/projet_cpp_4AESE/tree/main/appli)
  
## DESCRIPTION UML  
Avant de détailler l’implémentation, nous présentons ici une description UML de l’ensemble du projet. 
Cette description contient: un diagramme des uses cases, deux diagrammes de séquences, dont un qui décrit le comportement général du système et l’autre le cas de détection d’un danger, et enfin deux diagrammes des classes.  

### Use cases
![user case](https://user-images.githubusercontent.com/128903240/235663121-4138d28a-abcd-4ec0-8b22-39a8af73595d.png)  
### Diagrammes de séquence  
Ici, nous illustrons deux cas d'utilisation classiques: le cas où l'utilisateur utilise la voiturette en utilisant l'application (1), et le cas ou la voiturette détecte un danger(2).  
#### Diagramme 1  
![Diagramme de séquence général du système](https://i.ibb.co/HpJw1q8/s-quence-g-n-ral.png)  
#### Diagramme 2  
![Diagramme de séquence de l'arrêt d'urgence](https://i.ibb.co/gwf9wZx/Untitled.png)  
### Diagramme des classes
![diagramme_classes_global](https://github.com/kiso6/projet_cpp_4AESE/assets/128903240/20d7cd12-7fdf-4659-8e77-02a277747744)
### Diagramme des classes de la Voiturette  
![diagramme_classes_2](https://i.ibb.co/7nhsNNj/Diagramme-Classes-2.png)  

## DEMONSTRATION VIDEO  
A VENIR (W.I.P)  
<iframe width="853" height="480" src="https://www.youtube.com/embed/CWf8fXVRR34" title="Présentation voiturette télécommandée _ Raphael TESSIER et Kilian SOUAL" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>  


## CONCLUSION ET PERSPECTIVES D'AMELIORATION  
Pour conclure sur ce projet, on peut dire que notre cahier des charges à bien été respecté. Les fonctionnalités décrites par l'UML de notre projet son implémentées et fonctionnent plutôt bien. Il reste néanmoins quelques perspectives d'amélioration, le projet n'étant qu'une première version.   
En effet, nous pourrions penser à rajouter des capteurs d'ultrason en plus (arrière, côtés) de manière à repérer plus efficacement les obstacles.   
Aussi, nous avons constaté que la batterie du système s'use plutôt rapidement (~1h30 d'autonomie).  Nous pourrions alors envisager de remplacer le système de relais par un hacheur quatre quadrants, pour bénéficier d'une récupération d'énergie.

