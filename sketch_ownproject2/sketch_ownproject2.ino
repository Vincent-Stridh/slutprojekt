/*  
* Name: Train Project
* Author: Vincent Stridh
* Date: 2026-05-13
* Description: this project uses a dc motor and an IR reader to allow the user to use a remote to drive a train forwards or backwards
* Further, I might allow the user to change tracks as well.
*/  
//Libraries
#include <IRremote.h>

//Constants
const int relay1Pin = 8;
const int relay2Pin = 7;
const int RECV_PIN = 4;

//Variables
int IRValue;

//Objects
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  irrecv.enableIRIn();
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(RECV_PIN, INPUT);
  Serial.begin(9600);
  digitalWrite(relay1Pin, LOW);
  digitalWrite(relay2Pin, LOW);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if(results.value == 0xFF629D) { // forward button
      digitalWrite(relay1Pin, LOW);
      digitalWrite(relay2Pin, HIGH);
      Serial.println("FRONT");
    }
    else if(results.value == 0xFFA857) { // back button
      digitalWrite(relay1Pin, HIGH);
      digitalWrite(relay2Pin, LOW);
      Serial.println("BACK");
    }
    else { // any other button/off button
      digitalWrite(relay1Pin, LOW);
      digitalWrite(relay2Pin, LOW);
      Serial.println("OFF");
    }
    irrecv.resume();
  }
}