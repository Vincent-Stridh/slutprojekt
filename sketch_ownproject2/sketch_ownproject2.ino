/*  
* 
*/  
//Constants
#include <IRremote.h>

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

