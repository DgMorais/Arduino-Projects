/*******************************************************************************
* Kit Avançado para Arduino v4 - Liquid Crystal Display LCD
* Primeiros passos com um display LCD 16x2.
*******************************************************************************/

#include <LiquidCrystal.h> // inclui a biblioteca para uso do Display LCD
// inicializa um objeto nos pinos para acesso as funções do LCD
const int RS = 12, EN = 11, D4 = 10, D5 = 9, D6 = 8, D7 = 7;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

byte coracao[8]={B00000, B01010, B11111, B11111, B11111, B01110, B00100, B00000} ;
byte bateriaL[8]={B01110, B11011, B10001, B10001, B10001, B10001, B10001, B11111};
byte bateriaM[8]={B01110, B11011, B10001, B10001, B10001, B11111, B11111, B11111};
byte bateriaF[8]={B01110, B11111, B11111, B11111, B11111, B11111, B11111, B11111};

void setup(){
  // Configura o LCD com os número de colunas e linhas
  lcd.begin(16, 2); // 16 colunas e 2 linhas
  lcd.createChar(1, coracao);
  lcd.createChar(2, bateriaL);
  lcd.createChar(3, bateriaM);
  lcd.createChar(4, bateriaF);
}

void loop()
{
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.write(2);
  lcd.setCursor(0,1);
  lcd.write(1);

  delay(3000);

  lcd.setCursor(0,0);
  lcd.write(3);
  lcd.setCursor(0,1);
  lcd.write(1);

  delay(3000);

  lcd.setCursor(0,0);
  lcd.write(4);
  lcd.setCursor(0,1);
  lcd.write(1);

  delay(3000);
} 
