#include <SoftwareSerial.h>
#define DE 3
#define RE 2

SoftwareSerial mySerial(11, 10);
int ledPin = 13;
int ledPin1 = 12;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(DE, OUTPUT);
  pinMode(RE, OUTPUT);
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
}

void loop() {
  while (mySerial.available() > 0) {
    char c = mySerial.read();
    Serial.write(c);
    if (c == 'A') {
      digitalWrite(ledPin, HIGH);

    } else if (c == 'B') {
      digitalWrite(ledPin, LOW);
    }
    if (c == 'C') {
      digitalWrite(ledPin1, HIGH);

    } else if (c == 'D') {
      digitalWrite(ledPin1, LOW);
    }
  }
}