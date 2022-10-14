/*******************************************************************************
* RoboCore Kit Iniciante V8 - Construindo um Sensor de Luz 2
* Acender o LED quando o LDR indicar iluminação abaixo do limite.
*******************************************************************************/

const int pinoLDR = A0; // pino onde o LDR está conectado
const int pinoLED_VD = 7; // pino onde o LED verde esta conectado
/* const int pinoLED_AM = 6; // pino onde o LED amarelo esta conectado
const int pinoLED_VM = 5; // pino onde o LED vermelho esta conectado */
int leitura = 0; // variavel para armazenar o valor lido pelo ADC

void setup() {
  pinMode(pinoLDR, INPUT);
  pinMode(pinoLED_VD, OUTPUT);
  /*pinMode(pinoLED_AM, OUTPUT);
  pinMode(pinoLED_VM, OUTPUT);*/
  Serial.begin(9600);
}

void loop() {
  leitura = analogRead(pinoLDR);
  Serial.println(leitura);

  if (leitura <= 400) {
    digitalWrite(pinoLED_VD, HIGH);
    digitalWrite(pinoLED_AM, LOW);
    digitalWrite(pinoLED_VM, LOW);
  } else if (leitura > 400 && leitura <= 700) {
    digitalWrite(pinoLED_VD, LOW);
    digitalWrite(pinoLED_AM, HIGH);
    digitalWrite(pinoLED_VM, LOW);
  } else if (leitura > 700) {
    digitalWrite(pinoLED_VD, LOW);
    digitalWrite(pinoLED_AM, LOW);
    digitalWrite(pinoLED_VM, HIGH);
  }
  delay(500); // aguarda 500 milissegundos para uma nova leitura
}
