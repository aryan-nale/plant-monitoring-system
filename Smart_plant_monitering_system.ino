#include <LiquidCrystal.h>
const int LM35 = A0;
const int motor =13 ;
const int ledred = 12;
const int ledgreen = 11;
int prcentageValue =0;

LiquidCrystal Lcd(2,3,4,5,6,7);
void setup()
{
  Serial.begin(9600);
  Lcd.begin(16,2);
  Lcd.print("AUTOMATED CROP");
  Lcd.setCursor(0,1);
  Lcd.print("Water System");
  pinMode(motor,OUTPUT);
  pinMode(ledred,OUTPUT);
  pinMode(ledgreen,OUTPUT);
  delay(5000);
  Lcd.clear();
  Lcd.print("SOIL M. =");
  Lcd.setCursor(0,1);
  Lcd.print("WaterPUMP = ");
  
}

void loop()
{
  int value = analogRead(LM35);
  float Moistuer = value * 500.0/1023.0;
  Lcd.setCursor(10,0);
  Lcd.print(Moistuer);
  Lcd.setCursor(12,1);
  
  if (Moistuer < 300)
  {
    digitalWrite(motor,HIGH);
    digitalWrite(ledred,HIGH);
    digitalWrite(ledgreen,LOW);
    Lcd.print("ON");
  }
  else{
    digitalWrite(motor,LOW);
    digitalWrite(ledred,LOW);
    digitalWrite(ledgreen,HIGH);
    Lcd.print("OFF");
  
  }
 Serial.print("Moistuer");
  Serial.println(Moistuer);
}