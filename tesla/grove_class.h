#ifndef GROVE_CLASS_H
#define GROVE_CLASS_H

//Basic grove class
class Grove {
protected :
  //default initialized to 0
  const int pin1{0};
  const int pin1mode{0};
  const int pin2{0};
  const int pin2mode{0};
public :

  Grove(int p1, int p1m): pin1(p1), pin1mode(p1m) {};
  Grove(int p1, int p1m, int p2, int p2m): pin1(p1), pin1mode(p1m), pin2(p2), pin1mode(p1m){};;
  virtual Init() = 0;
  
=======
  //constructors
  Grove(int p1, int p1m);
  Grove(int p1, int p1m, int p2, int p2m);
  //virtual foncitons to define
  //virtual void Init() = 0;

};

/*class Capteur : public Grove {


};

class Ultrason : public Capteur {


};
*/
class Actionneur : public Grove {
public:
  Actionneur(int p1,int p1m);
  Actionneur(int p1,int p1m,int p2,int p2m);
};

class Led : public Actionneur {
public: 
  Led(int pin, int mode);
  void Init(int);
  void clignotant(int);
  void phare(bool);
};

class Buzzer: public Actionneur{
public:
  Buzzer(int pin, int mode);
  void Init(int);
  void klaxonner(int,bool);
};

/*
class Servo : public Actionneur {



};

class Moteur : public actionneur {

  
}

=======
};*/



#endif




