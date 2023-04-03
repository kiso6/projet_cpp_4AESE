const int ledPin = D5;     // the GPIO number of the pushbutton pin



void setup() {
    // initialize the pushbutton pin as an input:
    pinMode(ledPin, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);         // the Serial port of Arduino baud rate.
    Serial.print("test");
}

void loop(){
    // read the state of the pushbutton value:
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);

}