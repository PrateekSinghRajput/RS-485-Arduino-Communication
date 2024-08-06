#include <SoftwareSerial.h>
#define DE 3
#define RE 2

SoftwareSerial mySerial(11, 10);
int buttonPin = 5;
int buttonPin1 = 4;

void setup() {
  mySerial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(DE, OUTPUT);
  pinMode(RE, OUTPUT);
  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    mySerial.write('A');
  } else {
    mySerial.write('B');
  }

  if (digitalRead(buttonPin1) == LOW) {
    mySerial.write('C');
  } else {
    mySerial.write('D');
  }
  delay(100);
}