#ifndef GROVE_CLASS_H
#define GROVE_CLASS_H

//CLASSE DE BASE GROVE

class Grove {
protected : 
/*seuls attributs manipulés pour l'ensemble des classes du projet, ici en protected pour être accessibles par les classes filles
4 attributs, 2 pins et 2 pinmodes pour être capables de gérer tous les cas
*/
  int pin1{0};
  int pin1mode{0};
  int pin2{0};
  int pin2mode{0};
public :
//pas de methodes propre à la classe grove, on ne trouve que des constructeurs et destructeurs
  Grove();
  Grove(int p1, int p1m);
  Grove(int p1, int p1m, int p2, int p2m);
  Grove& operator=(const Grove& G);
  ~Grove();
};

//-----------------------------------
//CLASSES DERIVEES DE GROVE

//classe utilisée pour manipuler des capteurs, elle hérite de grove et n'implémente pas de nouveaux attributs
class Capteur : public Grove {
public:
  Capteur();
  Capteur(int p1,int p1m);
  Capteur(int p1,int p1m,int p2,int p2m);
  ~Capteur();
};

//classe utilisée pour manipuler des actionneurs, elle hérite de grove et n'implémente pas de nouveaux attributs
class Actionneur : public Grove {
public:
  Actionneur();
  Actionneur(int p1,int p1m);
  Actionneur(int p1,int p1m,int p2,int p2m);
  ~Actionneur();
};

#endif




