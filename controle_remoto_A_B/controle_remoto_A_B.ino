#include "IRremote.h"

const int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);

    if (results.value == 0xFF30CF) {
      Serial.println("Botão A pressionado!");
    }

    if (results.value == 0xFF18E7) {
      Serial.println("Botão B pressioando!");
    }

    irrecv.resume();
  }
}
