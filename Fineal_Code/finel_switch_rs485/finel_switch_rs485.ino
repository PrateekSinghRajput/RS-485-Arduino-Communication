#include <SoftwareSerial.h>
#define DE 3
#define RE 2

SoftwareSerial mySerial(11, 10);
const int numSwitches = 30;
int switchPins[numSwitches] = { 4,5,6,7,8,9,14,15,16,17,18,19,20,21,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,51};

void setup() {
  mySerial.begin(9600);
   for (int i = 0; i < numSwitches; i++) {
    pinMode(switchPins[i], INPUT_PULLUP);  // Using internal pull-up resistors
  }
  pinMode(DE, OUTPUT);
  pinMode(RE, OUTPUT);
  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
}

void loop() {
   byte switchStates[numSwitches];
  
  // Read the state of each switch
  for (int i = 0; i < numSwitches; i++) {
    switchStates[i] = digitalRead(switchPins[i]) == LOW ? 1 : 0;
  }

  // Transmit the switch states via RS485
  mySerial.write(switchStates, numSwitches);

  // Add a short delay
  delay(100);
}