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
    Serial.print("Hexadecimal: ");
    Serial.println(results.value, HEX);

    switch (results.value) {
      case 0xFFA25D:
        Serial.println("Botão ON/OFF pressionado!");
        break;
      case 0xFFE21D:
        Serial.println("Botão ROBOCORE pressionado!");
        break;
      case 0xFF02FD:
        Serial.println("Botão 'seta para cima' pressionado!");
        break;
      case 0xFFE01F:
        Serial.println("Botão 'seta para esquerda' pressionado!");
        break;
      case 0xFF906F:
        Serial.println("Botão 'seta para direita' pressionado!");
        break;
      case 0xFF9867:
        Serial.println("Botão 'seta para baixo' pressionado!");
        break;
      case 0xFFA857:
        Serial.println("Botão 'OK' pressionado!");
        break;
      case 0xFF30CF:
        Serial.println("Botão A pressionado!");
        break;
      case 0xFF18E7:
        Serial.println("Botão B pressionado!");
        break;
      case 0xFF7A85:
        Serial.println("Botão C pressionado!");
        break;
      case 0xFF10EF:
        Serial.println("Botão D pressionado!");
        break;
      case 0xFF38C7:
        Serial.println("Botão E pressionado!");
        break;
      case 0xFF5AA5:
        Serial.println("Botão F pressionado!");
        break;
      case 0xFF42BD:
        Serial.println("Botão G pressionado!");
        break;
      case 0xFF4AB5:
        Serial.println("Botão H pressionado!");
        break;
      case 0xFF52AD:
        Serial.println("Botão I pressionado!");
        break;
      default:
        Serial.println("Botão não encontrado!");
        break;
    }

    Serial.println("");
    irrecv.resume();
  }
}
