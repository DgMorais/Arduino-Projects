/*******************************************************************************
* RoboCore Kit Iniciante V8 - 14. Projeto Missão Impossível Desafio
* Detectar a presença de obstáculos a partir de um diodo laser e um LDR.
*******************************************************************************/

const int pinoLDR = A0;
const int pinoBuzzer = 9;
const int pinoBotao = 8;

int leituraLDR = 0;
int leituraBotao;
int contador = 0;
int flag = 0;

void setup() {
  Serial.begin(9600);

  pinMode(pinoLDR, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoBotao, INPUT_PULLUP);
}

void loop() {
  leituraLDR = analogRead(pinoLDR); // lê o valor da tensão no pino LDR
  leituraBotao = digitalRead(pinoBotao); // lê o estado do botão

  // Imprime o valor lido pelo arduino (0 a 1023)
  Serial.print("Leitura: "); 
  Serial.print(leituraLDR);
  Serial.print("\t");

  if (leituraBotao == LOW) {
    contador = 0;
    Serial.println(contador);
    delay(100);
  }

  if (leituraLDR <= 600 && flag == 0) {
    contador++;
    flag = 1;
    Serial.println(contador);
    tone(pinoBuzzer, 1000);
    delay(100);
    noTone(pinoBuzzer);
  } else if (leituraLDR > 600 && flag == 1) {
    flag = 0;
  }

  Serial.println();
  delay(100);
}
