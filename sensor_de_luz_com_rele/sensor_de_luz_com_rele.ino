/*******************************************************************************
* RoboCore Kit Iniciante V8 - Construindo um Sensor de Luz 2
* Acender o LED quando o LDR indicar iluminação abaixo do limite.
*******************************************************************************/

const int pinoLDR = A0; // pino onde o LRD está conectado
int rele = 3;
float tensao = 0.0;
int leitura = 0; // variável para armazenar o valor lido pelo ADC

void setup() {
  // Inicia e configura a Serial
  Serial.begin(9600); // 9600bps

  // configura o pino com LDR como entrada
  pinMode(pinoLDR, INPUT); // pino A0
  pinMode(rele, OUTPUT);
}

void loop() {
  // le o valor de tensão no pino do LDR
  leitura = analogRead(pinoLDR);

  if(leitura < 600){ // se a luminosidade for menor que 40
    digitalWrite(rele, HIGH);
  } else { // se não
    digitalWrite(rele, LOW); 
  }

  // imprime valor lido pelo arduino (0 a 1023)
  Serial.print("Leitura: ");
  Serial.print(leitura);
  Serial.print("\t"); // tabulacao

  // converte e imprime o valor em tensão elétrica
  tensao = leitura * 5.0 / 1024.0;
  Serial.print("Tensão: ");
  Serial.print(tensao);
  Serial.print("V");

  Serial.println(); // nova linha

  delay(1000); // aguarda 1 segundo para uma nova leitura
}
