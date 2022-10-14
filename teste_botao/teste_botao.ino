void setup() {
  pinMode(9, INPUT); // configura o pino com o botão como entrada
  pinMode(10, OUTPUT); // configura o pino com o LED como saída
  pinMode(4, OUTPUT); // configura o pino com o LED como saída
}

void loop() {
  if (digitalRead(9) == HIGH) { // Se o botão estiver pressionado (HIGH)
    digitalWrite(12, HIGH); // acende o LED
    digitalWrite(4, LOW);
  } else { // Se não estiver pressionado (LOW)
    digitalWrite(12,LOW); // apaga o LED
    digitalWrite(4, HIGH);
  }
}
