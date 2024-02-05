#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

const int hijauLED = 7;
const int kuningLED = 6;
const int orangeLED = 5;
const int merahLED = 4;
const int buzzer = 3;

int level;
int sensor = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(hijauLED, OUTPUT);
  pinMode(kuningLED, OUTPUT);
  pinMode(orangeLED, OUTPUT);
  pinMode(merahLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
 
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print(" ");
 delay(1000);
}
void loop() {
  // put your main code here, to run repeatedly:
  level = analogRead(sensor);
  lcd.setCursor(0,0);
  lcd.print(level);
  lcd.print(" ");
  lcd.setCursor(0,1);
  
  if(level == 0) {
  lcd.print("AMAN");
  digitalWrite(hijauLED, HIGH);
  digitalWrite(kuningLED, LOW);
  digitalWrite(orangeLED, LOW);
  digitalWrite(merahLED, LOW);
  digitalWrite(buzzer, LOW);
  }
  else if (level > 0 && level <= 340) {
  lcd.print("PERINGATAN");
  digitalWrite(hijauLED, LOW);
  digitalWrite(kuningLED, HIGH);
  digitalWrite(orangeLED, LOW);
  digitalWrite(merahLED, LOW);
  digitalWrite(buzzer, LOW);
  }
  else if (level > 340 && level <= 680) {
  lcd.print("WASPADA");
  digitalWrite(hijauLED, LOW);
  digitalWrite(kuningLED, LOW);
  digitalWrite(orangeLED, HIGH);
  digitalWrite(merahLED, LOW);
  digitalWrite(buzzer, LOW);
  }
  else if (level > 680) {
  lcd.print("BAHAYA");
  digitalWrite(hijauLED, LOW);
  digitalWrite(kuningLED, LOW);
  digitalWrite(orangeLED, LOW);
  digitalWrite(merahLED, HIGH);
  digitalWrite(buzzer, HIGH);
  }
  delay(500);
}