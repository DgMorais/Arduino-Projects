#include "IRremote.h"

const int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
boolean stats_rele = false;
const int rele = 12;

void setup()
{
  pinMode(rele, OUTPUT);
  digitalWrite(rele, LOW);
  Serial.begin(9600);
  irrecv.enableIRIn(); //começa a receber
}

void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);
  
  if (results.value == 0x20DF10EF){
      if (stats_rele == false) {
        stats_rele = true;
        Serial.println("Liga");
        digitalWrite(rele, HIGH);
      } else {
        stats_rele = false;
        Serial.println("Desliga");
        digitalWrite(rele, LOW);
      }
  }
   
  irrecv.resume(); // Recebe o próximo valor
  }
}
