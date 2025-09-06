#include <SoftwareSerial.h>
#define DE 3
#define RE 2

SoftwareSerial mySerial(11, 10);
const int numLEDs = 30;
int ledPins[numLEDs] = { 44,32,20, 46,34,21, 48,36,24, 40,38,26, 50,52,28, 51,42,30, 19,18,17,15};

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], HIGH);  // Ensure all LEDs are off initially
  }
  pinMode(DE, OUTPUT);
  pinMode(RE, OUTPUT);
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
}

void loop() {
  if (mySerial.available() > 0) {
    // Read the data (assume it's a 30-byte array)
    byte switchStates[numLEDs];
    mySerial.readBytes(switchStates, numLEDs);

    // Update LED states
    for (int i = 0; i < numLEDs; i++) {
      if (switchStates[i] == 1) {        // Switch pressed
        digitalWrite(ledPins[i], LOW);  // Turn on the LED
      } else {
        digitalWrite(ledPins[i], HIGH);  // Turn off the LED
      }
    }
  }
}