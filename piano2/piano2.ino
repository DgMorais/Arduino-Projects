  /*******************************************************************************
  * Kit Iniciante para Arduino v8 - Projeto Piano 2
  * Reproduzir notas músicais em um buzzer de acordo com os botões pressionados.
  *******************************************************************************/

  // pino onde os botões estão conectados
  const int pino_botao1 = 7;
  const int pino_botao2 = 8;
  const int pino_botao3 = 9;

  // pino onde o buzzer está conectado
  const int pino_buzzer = 10;

  // pino onde os LEDs estão conectados
  const int pino_led1 = 11;
  const int pino_led2 = 12;
  const int pino_led3 = 13;

  // Frequências de cada nota musical
  const int c = 261; // Dó
  const int d = 293; // Ré
  const int e = 329; // Mi
  
void setup() {
  // Configura os pinos
  pinMode(pino_botao1, INPUT_PULLUP); 
  pinMode(pino_botao2, INPUT_PULLUP); 
  pinMode(pino_botao3, INPUT_PULLUP); 
  pinMode(pino_buzzer, OUTPUT); 
  pinMode(pino_led1, OUTPUT); 
  pinMode(pino_led2, OUTPUT); 
  pinMode(pino_led3, OUTPUT); 
}

void loop() {
  // Salva o estado de cada botão
  bool estado_botao1 = digitalRead(pino_botao1);
  bool estado_botao2 = digitalRead(pino_botao2);
  bool estado_botao3 = digitalRead(pino_botao3);

  if (estado_botao1 == LOW) {
    tone(pino_buzzer, c); // Dó
    digitalWrite(pino_led1, HIGH);
    digitalWrite(pino_led2, LOW);
    digitalWrite(pino_led3, LOW);
  } else if (estado_botao2 == LOW) {
    tone(pino_buzzer, d); // Ré
    digitalWrite(pino_led1, LOW);
    digitalWrite(pino_led2, HIGH);
    digitalWrite(pino_led3, LOW);
  } else if (estado_botao3 == LOW) {
    tone(pino_buzzer, e); // Mi
    digitalWrite(pino_led1, LOW);
    digitalWrite(pino_led2, LOW);
    digitalWrite(pino_led3, HIGH);
  } else {
    noTone(pino_buzzer); // desliga buzzer
    digitalWrite(pino_led1, LOW);
    digitalWrite(pino_led2, LOW);
    digitalWrite(pino_led3, LOW);
  }
}
