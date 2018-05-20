#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
const int inPin = 0;

int ledRosu = 6;
int ledAlba = 7;

int tempMIN = 20;
int tempMAX = 30;

void setup(){
  lcd.begin(16,2);

  pinMode(ledRosu, OUTPUT);
  pinMode(ledAlba, OUTPUT);
}
void loop(){
  int value = analogRead(inPin);
  lcd.setCursor(0,1);
  float millivolts = (value* (3300/1024) );
  float celsius = millivolts / 100;

  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(celsius);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print((celsius * 9)/5 + 32);
  lcd.print("F");

  if (celsius < tempMIN){
    digitalWrite(ledAlba, HIGH);
    digitalWrite(ledRosu, LOW);
    lcd.setCursor(11,0);
    lcd.print("RECE");
  }else if (celsius > tempMAX){
    digitalWrite(ledRosu, HIGH);
    digitalWrite(ledAlba, LOW);
    lcd.setCursor(11,0);
    lcd.print("CALD");
  }else{
    digitalWrite(ledRosu, LOW);
    digitalWrite(ledAlba, LOW);
    lcd.setCursor(11,0);
    lcd.print("STOP");
  }
  
  delay(1000);
}
