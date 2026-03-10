/*  
* Name: Train Project
* Author: Vincent Stridh
* Date: 2026-03-10
* Description: this project uses a dc motor and an IR reader to allow the user to use a remote to drive a train forwards or backwards
* Further, I might allow the user to change tracks as well.
*/  
//Libraries
#include <IRremote.h>

//Constants
const int relayPin = 8;
const int RECV_PIN = 11;

//Variables
int IRValue;

//Objects
IRrecv irrecv(RECV_PIN);
decode_results  results;

void setup() {
  irrecv.enableIRIn();
  pinMode(relayPin, OUTPUT);
  pinMode(RECV_PIN, INPUT);
  Serial.begin(9600);
  digitalWrite(relayPin, LOW);
}

void loop() {
  if (irrecv.decode(&results))  {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive  the next value
    digitalWrite(relayPin, HIGH);
    Serial.println("HIGH");
  }
  else {
    digitalWrite(relayPin, LOW);
    Serial.println("LOW");
  }
  delay(100);
}

