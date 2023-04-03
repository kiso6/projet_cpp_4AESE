class Grove {
protected :
  const int pin1;
  const int pin1mode;
  const int pin2;
  const int pin2mode;

public :
  Grove(int p1, int p1m);
  Grove(int p1, int p1m, int p2, int p2m);
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






void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
