/*******************************************************************************
* RoboCore Kit Iniciante V8 para Arduino - Gravity Falls *
*******************************************************************************/

const int buzzer = 10;
const int LED_G = 11;
const int LED_R = 13;

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;
 
int counter = 0;
 
void setup() {
  pinMode(buzzer, OUTPUT); // Configura o pino do Buzzer como saída
  pinMode(LED_G, OUTPUT); // Configura o pino do LED verde como saída
  pinMode(LED_R, OUTPUT); // Configura o pino do LED vermelho como saída
}
 
void loop() {
 
  firstSection();

  delay(150);
  
  secondSection();
 
  delay(650);
}
 
void beep(int note, int duration) {
  //Play tone on buzzerPin
  tone(buzzer, note, duration);
 
  //Play different LED depending on value of 'counter'
  if(counter % 2 == 0) {
    digitalWrite(LED_G, HIGH);
    delay(duration);
    digitalWrite(LED_G, LOW);
  } else {
    digitalWrite(LED_R, HIGH);
    delay(duration);
    digitalWrite(LED_R, LOW);
  }
 
  //Stop tone on buzzerPin
  noTone(buzzer);
 
  delay(50);
 
  //Increment counter
  counter++;
}
 
void firstSection() {
  beep(d, 700);
  beep(e, 250);    
  beep(f, 700);
  delay(500);
  beep(a, 500);
  beep(g, 500);    
  beep(a, 250);
  beep(c, 700);
  delay(500);  
  beep(d, 700);
  beep(e, 250);
  beep(f, 500);
  beep(e, 600);
  beep(g, 600);
  beep(a, 600);
  beep(g, 600);
  beep(f, 700);
}
 
void secondSection() {
  beep(f, 320);
  beep(f, 285);
  beep(f, 285);
  beep(a, 285);
  beep(a, 285);
  beep(g, 285);
  beep(f, 285);
  delay(150);
  beep(a, 285);
  beep(a, 285);
  beep(a, 285);
  beep(g, 285);
  beep(a, 285);
  beep(g, 285);
  beep(f, 285);
  delay(170);
  beep(f, 285);
  beep(f, 285);
  beep(f, 285);
  beep(a, 285);
  beep(a, 285);
  beep(g, 285);
  beep(f, 285);
  delay(170);
  beep(a, 285);
  beep(a, 285);
  beep(a, 285);
  delay(150);
  beep(cH, 285);
  beep(cH, 285);
  beep(cH, 285);
  delay(170);
  beep(f, 285);
  beep(f, 285);
  beep(f, 285);
  beep(a, 285);
  beep(a, 285);
  beep(g, 285);
  beep(f, 285);
  delay(170);
  beep(b, 285);
  beep(b, 285);
  beep(b, 285);
  beep(g, 700);
  beep(c, 500);
  beep(a, 500);
  beep(cH, 500);
  delay(50);
  beep(f, 100);
  beep(d, 150);
  beep(f, 100);
  beep(d, 150);
  beep(a, 100);
  beep(c, 150);
  beep(d, 150);
  beep(d, 150);
  beep(d, 150);
  beep(d, 100);
}
