/*******************************************************************************
* RoboCore Kit Iniciante V8 - Trabalhando com Gráficos 1
* Imprime na Serial o valor de tensão na saída do potenciômetro.
*******************************************************************************/

const int pinoPotenciometro = A0; // pino onde o potenciometro esta conectado
int leitura = 0;
float tensao = 0.0;

void setup() {
  Serial.begin(9600);

  pinMode(pinoPotenciometro, INPUT);
}

void loop() {
  leitura = analogRead(pinoPotenciometro); // le o valor de tensão no pino do potenciômetro

  tensao = leitura * 5.0 / 1023.0; // converte e imprime o valor em tensao elétrica

  Serial.println(leitura);
  Serial.println(" ");
  Serial.println(tensao*100); // imprime o valor no plotter serial
  Serial.println(" ");
  Serial.println(tensao*90);
  Serial.println(" ");
  Serial.println(leitura/2);
  Serial.println(" ");
  Serial.println(tensao*80);

  delay(100); // aguarda 100 milissegundos para uma nova leitura
}
