int frequencia = 2000; // frequencia inicial do buzzer
const int pinoBuzzer = 10; // pino onde o buzzer esta conectado
const int pinoBotao1 = 9; // pino onde o botao 1 esta conectado
const int pinoBotao2 = 11; // pino onde o botao 2 esta conectado

void setup() {
  pinMode(pinoBuzzer, OUTPUT); // configura o pino com o buzzer como saída
  pinMode(pinoBotao1, INPUT_PULLUP); // configura o pino com o Botão como entrada 
  pinMode(pinoBotao2, INPUT_PULLUP); // configura o pino com o Botao como entrada
}

void loop() {
  // Soma 100 a frequencia atual se o botao estiver pressionado
  if (digitalRead(pinoBotao1) == LOW) {
    frequencia = frequencia + 100;
  }

  // Subtrai 100 da frequencia atual se o botao estiver pressionado
  if (digitalRead(pinoBotao2) == LOW) {
    frequencia = frequencia - 100;
  }
  
  tone(10, frequencia); // gera frequencia de 2000Hz no buzzer
  delay(1000);
  noTone(10); // para frequencia no buzzer
  delay(1000);
}
