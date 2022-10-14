  /*******************************************************************************
  * RoboCore Kit Iniciante V8 - Construindo um Sensor de Luz 1
  * Imprime na Serial o valor de tensão do LDR.
  *******************************************************************************/
  const int pinoLDR = A0; // pino onde o LDR está conectado
  const int pinoLED = 7; // pino onde o LED está conectado
  int leitura = 0;
  float tensao = 0.0;

void setup() {
  // Inicia e configura a Serial
  Serial.begin(9600); // 9600bps

  // configura o pino LDR como entrada
  pinMode(pinoLDR, INPUT); // pino A0
  pinMode(pinoLED, OUTPUT);
}

void loop() {
  // lê o valor de tensão no pino do LDR
  leitura = analogRead(pinoLDR);

  // verifica luminosidadedo ambiente
  if (leitura < 500) { // se a luminosidade for menor que 40
    digitalWrite(pinoLED, HIGH); // acende o LED
  } else { // se não
    digitalWrite(pinoLED, LOW); // apaga o LED
  }

  // Imprime valor lido pelo arduino (0 a 1023)
  Serial.print("Leitura: ");
  Serial.print(leitura);
  Serial.print("\t"); //tabulação

  // converte e imprime o valor em tensão elétrica
  tensao = leitura * 5.0 / 1023.0;
  Serial.print("Tensão: ");
  Serial.print(tensao);
  Serial.print("V");

  Serial.println(); // nova linha

  delay(1000); // agurda 1 segundo para uma nova leitura
}
