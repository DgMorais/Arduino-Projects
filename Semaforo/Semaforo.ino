void setup() {
  // Configura os pinos com os LED's como saída
  pinMode(13, OUTPUT); // Led Verde
  pinMode(12, OUTPUT); // Led Amarelo
  pinMode(11, OUTPUT); // Led Vermelho
  pinMode(10, OUTPUT); // Led Vermelho Pedestres
  pinMode(9, OUTPUT); // Led Verde Pedestres
}

void loop() {
  // Semaforo para Pedestres
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  //Semaforo para Veiculos
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(5000);

  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  delay(2000);

  // Semaforo para Pedestres
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  //Semaforo para Veiculos
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(6000);
}
