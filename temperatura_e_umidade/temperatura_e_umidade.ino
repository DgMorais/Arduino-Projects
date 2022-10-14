/*******************************************************************************
* Kit Iniciante para Arduino v8 - Utilizando o DHT11
* Mostrar os valores de Tempartura e Umidade no Monitor Serial.
*******************************************************************************/

// Inclui a biblioteca DHT que possui as funções dos sensores do tipo DHT
#include <DHT.h>
#include <DHT_U.h>

const int pino_dht = 9; // Pino onde o sensor DHT está conectado
float temperatura; // Variável para armazenar o valor da temperatura
float umidade; // Variável para armazenar o valor da umidade
DHT dht(pino_dht, DHT11); // Define o pino e o tipo de DHT
 
void setup() {
  Serial.begin(9600);

  dht.begin(); // Inicializa o sensor DHT
}

void loop() {
  // Aguarda alguns segundos entre uma leitura e outra
  delay(2000); // 2 segundos (Datasheet)

  // A leitura da temperatura ou umidade pode levar 250ms
  // O atraso do sensor pode chegar a 2 segundos
  temperatura = dht.readTemperature(); // Lê a temperatura em Celsius
  umidade = dht.readHumidity(); // Lê a umidade

  // Se ocorreu alguma falha durante a leitura
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Falha na leitura do sensor DHT!");
  } else {
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" *C ");

    Serial.print("\t");

    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.print(" %\t ");

    Serial.println();
  }
}
