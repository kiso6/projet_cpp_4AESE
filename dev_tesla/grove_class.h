#ifndef GROVE_CLASS_H
#define GROVE_CLASS_H

//Basic grove class
class Grove {
public :
  const int pin1{0};
  const int pin1mode{0};
  const int pin2{0};
  const int pin2mode{0};
public :
  Grove();
  Grove(int p1, int p1m);
  Grove(int p1, int p1m, int p2, int p2m);
  //virtual foncitons to define
  //virtual void Init() = 0;
  ~Grove();
};


class Capteur : public Grove {
public:
  Capteur();
  Capteur(int p1,int p1m);
  Capteur(int p1,int p1m,int p2,int p2m);
  ~Capteur();
};

/*
class Ultrason : public Capteur {
private:
    long duration(uint32_t timeout = 1000000L);
public:
    Ultrason(int pin);
    long MeasureInCentimeters(uint32_t timeout = 1000000L);
    long MeasureInMillimeters(uint32_t timeout = 1000000L);
    long MeasureInInches(uint32_t timeout = 1000000L);
};
*/
class Actionneur : public Grove {
public:
  Actionneur();
  Actionneur(int p1,int p1m);
  Actionneur(int p1,int p1m,int p2,int p2m);
  ~Actionneur();
};

/*
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
*/
/*
class Servo : public Actionneur {


};*/


#endif




