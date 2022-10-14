/*******************************************************************************
* RoboCore Kit Iniciante V8 - 14. Projeto Missão Impossível 1
* Detectar a presença de obstáculos a partir de um diodo laser e um LDR.
*******************************************************************************/

const int pinoLDR = A0;
const int pinoBuzzer = 9;
const int pinoBotao = 8;

int leituraLDR = 0;
int leituraBotao;

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

  // Imprime se existe ou não um obstáculo
  Serial.print("Obstaculo: ");
  if (leituraLDR <= 900) {
    Serial.print("Sim");
    tone(pinoBuzzer, 1000); // aciona o buzzer
  } else  if (leituraBotao == LOW) { // senão e o botão estiver pressionado
    Serial.print("Não"); // desliga o buzzer
    noTone(pinoBuzzer); 
  }

  Serial.println(); 

  delay(100);
}
