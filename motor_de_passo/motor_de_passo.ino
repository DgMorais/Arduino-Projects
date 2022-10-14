const int pot = A0;
int i;
int pins[] = {8,9,10,11};
int side = 0;
int velocidade = 0;

void setup() {
  Serial.begin(9600);
  Serial.print("Digite 0 ou 1: ");
  for (i = 0; i < 4; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  if (Serial.available() > 0) {
    side = Serial.read();
    Serial.println("");
  }

  velocidade = analogRead(pot);
  velocidade = map(velocidade, 0, 1023, 1, 100);

  if (side == 49) {
    Serial.print("Horario -> Velocidade: ");
    Serial.println(velocidade);
    for (i = 0; i < 5; i++) {
      digitalWrite(pins[i], HIGH);
      delay(velocidade);
      digitalWrite(pins[i], LOW);
    }
  }

  if (side == 48) {
    Serial.print("Anti-Horario -> Velocidade: ");
    Serial.println(velocidade);
    for (i = 4; i > -1; i--) {
      digitalWrite(pins[i], HIGH);
      delay(velocidade);
      digitalWrite(pins[i], LOW);
    }
  }
}
