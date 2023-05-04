/*
  Basic Ticker usage
  Ticker is an object that will call a given function with a certain period.
  Each Ticker calls one function. You can have as many Tickers as you like,
  memory being the only limitation.
  A function may be attached to a ticker and detached from the ticker.
  There are two variants of the attach function: attach and attach_ms.
  The first one takes period in seconds, the second one in milliseconds.
  The built-in LED will be blinking.
*/

#include <Ticker.h>

Ticker flipper;
Ticker flipper2;

int count = 0;

void flip() {
  int state = digitalRead(D5);  // get the current state of GPIO1 pin
  digitalWrite(D5, !state);     // set pin to the opposite state

}

void flip2() {
  int state = digitalRead(D6);  // get the current state of GPIO1 pin
  digitalWrite(D6, !state);     // set pin to the opposite state
}


void setup() {
  pinMode(D5, OUTPUT);
  digitalWrite(D5, LOW);
  pinMode(D6, OUTPUT);
  digitalWrite(D6, LOW);

  // flip the pin every 0.3s
  flipper.attach(0.3, flip);
  flipper2.attach(0.3, flip2);
}

void loop() {
}
