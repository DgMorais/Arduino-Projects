#include <LiquidCrystal.h>

#define btnShot 4

const int RS = 12, EN = 11, D4 = 10, D5 = 9, D6 = 8, D7 = 7;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

const int VRX = A4;
const int VRY = A5;
int leitura_VRX, leitura_VRY;

int speed = 200;
int pxSpaceShip, pySpaceShip, pxAst, pyAst, pxEnergy, pyEnergy, pxShot, pyShot;
bool game, vShot, vBattery;
int points;
double vEnergy;
int vScreen;
int maxPoints;

byte spaceship[8]={B11000,B01100,B01110,B01111,B01111,B01110,B01100,B11000};
byte asteroid[8]={B00000,B00100,B01110,B10111,B11101,B01110,B00100,B00000};
byte crash[8]={B10001,B01010,B01110,B00100,B01110,B01010,B10001,B00000};
byte battery[8]={B00000,B00000,B00100,B01010,B01010,B01110,B00000,B00000};
byte shot[8]={B00000,B00000,B00000,B00011,B00011,B00000,B00000,B00000};

void setup() {
  pxSpaceShip = pySpaceShip = pyAst = points = pxEnergy = pyEnergy = pyShot = 0;
  pxShot = -1;
  pxAst = 12;
  vEnergy=100;
  vScreen = 0;
  maxPoints = 20;

  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);

  lcd.createChar(1, spaceship);
  lcd.createChar(2, asteroid);
  lcd.createChar(3, crash);
  lcd.createChar(4, battery);
  lcd.createChar(5, shot);

  lcd.begin(16,2);
  lcd.clear();

  game = false;
  vShot = vBattery = false;
}

void loop() {
  if (game) {
    leitura_VRX = analogRead(VRX);
    leitura_VRY = analogRead(VRY);
    
    vEnergy -= 0.25;
    lcd.clear();
    if (vEnergy <= 0) {
      game = false;
      vScreen = 2;
    }
    panel(13);
    if (leitura_VRY > 700) {
      pySpaceShip = 0;
    }
    if (leitura_VRY < 300) {
      pySpaceShip = 1;
    } 
    if (digitalRead(btnShot) == 1) {
      pxShot = 1;
      vShot = true;
      pyShot = pySpaceShip;
    }

    pxAst-=1;
    drawSpaceShip(pxSpaceShip, pySpaceShip);
    drawAsteroid(pxAst, pyAst);
    
    if(vShot) {
      drawShot(pxShot, pyShot);
      pxShot+=1;
    }
    if (pxAst < 0) {
      pxAst = 12;
      pyAst = random(0,2);
    }
    if (pxShot > 16) {
      vShot = false;
      pxShot = -1;
    }
    if ((pxShot == pxAst+1 && pyShot == pyAst+1) || (pxShot == pxAst && pyShot == pyAst)) {
      vShot = false;
      pxShot = -1;
      drawAsteroidExplosion(pxAst, pyAst);
      pxAst = 12;
      pyAst = random(0,2);
      points+=2;
      if (points == maxPoints) {
        game = false;
        vScreen = 1;
      }
    }

    if (pxSpaceShip == pxAst && pySpaceShip == pyAst) {
      game = false;
      drawSpaceShipExplosion(pxSpaceShip, pyAst);
      vScreen = 2;
    }

    if (!vBattery) {
      if (random(0,60) > 58) {
        pxEnergy = 12;
        vBattery = true;
        pyEnergy = random(0,2);
      }
    } else {
      pxEnergy = -1;
      drawBattery(pxEnergy, pyEnergy);
      if ((pxSpaceShip == pxEnergy+1 && pySpaceShip == pyEnergy+1) || (pxSpaceShip == pxAst && pySpaceShip == pyEnergy)) {
        vBattery = false;
        pxEnergy = -1;
        vEnergy = 100;
      }
    }
    
    delay(speed);
  } else {
    statusGame(vScreen);
    if (digitalRead(btnShot) == 1) {
      resetGame();
    }
  }
}

void drawSpaceShip(int px, int py) {
  lcd.setCursor(px, py);
  lcd.write(1);
}

void drawAsteroid(int px, int py) {
  lcd.setCursor(px, py);
  lcd.write(2);
}

void drawSpaceShipExplosion(int px, int py) {
  lcd.clear();
  lcd.setCursor(px, py);
  lcd.write(3);
  delay(1000);
  lcd.clear();
}

void drawAsteroidExplosion(int px, int py) {
  lcd.setCursor(px, py);
  lcd.write(3);
  delay(1000);
  lcd.clear();
}

void drawBattery(int px, int py) {
  lcd.setCursor(px, py);
  lcd.write(4);
}

void drawShot(int px, int py) {
  lcd.setCursor(px, py);
  lcd.write(5);
}

void resetGame() {
  points = 0;
  vEnergy = 100;
  game = true;
  vScreen = 0;
}

void panel(int px) {
  lcd.setCursor(px, 0);
  lcd.print(points);
  lcd.setCursor(px, 1);
  lcd.print(vEnergy);
}

void statusGame(int status) {
  if (status < 1) {
    lcd.setCursor(1,0);
    lcd.print("SpaceShip Game");
    lcd.setCursor(1, 1);
    lcd.print("Pressione tiro"); 
  } else {
    String txt = {(status == 1  ? "Venceu" : "Game Over")};
    lcd.setCursor(10, 0);
    lcd.print("Pts:");
    lcd.setCursor(14, 0);
    lcd.print(points);
    lcd.setCursor(0, 0);
    lcd.print(txt);
    lcd.setCursor(0, 1);
    lcd.print("Pressione tiro"); 
  }
}
