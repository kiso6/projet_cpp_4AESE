class Grove {
protected :
  const int pin1;
  const int pin1mode;
  const int pin2;
  const int pin2mode;

public :
  Grove(int p1, int p1m): pin1(p1), pin1mode(p1m) {};
  Grove(int p1, int p1m, int p2, int p2m): pin1(p1), pin1mode(p1m), pin2(p2), pin1mode(p1m){};;
  virtual Init() = 0;
  
};

class Capteur : public Grove {


};

class Ultrason : public Capteur {


};

class Actionneur : public Grove {


};

class Led : public Actionneur {


};

class Servo : public Actionneur {


};

class Moteur : public actionneur {

  
}







