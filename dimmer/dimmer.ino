/*******************************************************************************
* RoboCore Kit Iniciante V8 - 16. - Pisca-Pisca
* Usar um potenciômetro para controlar o período com que um LED pisca.
*******************************************************************************/

const int pinoPotenciometro = A0;
const int pinoLED = 12;
const int periodo = 1023;
int tempo_ligado, tempo_desligado;

void setup() {
  pinMode(pinoPotenciometro, INPUT);
  pinMode(pinoLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  tempo_ligado = analogRead(pinoPotenciometro); // lê o valor de tensão no pino do potenciometro
  tempo_desligado = periodo - tempo_ligado; // atribui a variavel tempo_desligado, quanto tempo o LED deverá permanecer desligado

  digitalWrite(pinoLED, HIGH); // aciona o LED
  delay(tempo_ligado);
  digitalWrite(pinoLED, LOW); // apaga o LED
  delay(tempo_desligado);
  Serial.print(tempo_ligado);
  Serial.print("\t");
  Serial.println(tempo_desligado);
}
