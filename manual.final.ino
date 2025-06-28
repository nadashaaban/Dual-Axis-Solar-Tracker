#include <Wire.h>
#include<IRremote.hpp>
#include<LiquidCrystal.h>
#include<LiquidCrystal_I2C.h>
IRrecv IR(11);
#define side_3 3 
#define side_4 4
#define bottom_5 5
#define bottom_6 6
#define up A1
#define left A0
#define down A3
#define right A2
#define EN_side 10
#define EN_bottom 9
//LiquidCrystal lcd(2,7,13,12,11,10);
LiquidCrystal_I2C lcd (0x27,16,2);

int speed_side=0;
int speed_bottom=0;

void enable_speedV(int x){
  Serial.println(x);
  analogWrite(x,60);
   delay(300);
  for(int i=60;i>0;i--)
  {
     analogWrite(x,i);
    
    }

}
void enable_speedH(int x){
  Serial.println(x);
  analogWrite(x,80);
   delay(300);
  for(int i=80;i>0;i--)
  {
     analogWrite(x,i);
    
    }
}
void setup() {

pinMode(side_3,OUTPUT);
pinMode(side_4,OUTPUT);

pinMode(bottom_6,OUTPUT);
pinMode(bottom_5,OUTPUT);
pinMode(EN_side,OUTPUT);
pinMode(EN_bottom,OUTPUT);

digitalWrite(side_3,0);
digitalWrite(side_4,0);

digitalWrite(bottom_6,0);
digitalWrite(bottom_5,0);

 Serial.begin(9600);
  IR.enableIRIn();
  lcd.init();
 lcd.backlight();
}

void loop() {
   
  if(IR.decode()){
    Serial.println(IR.decodedIRData.decodedRawData);
    if(IR.decodedIRData.decodedRawData==0xE718FF00){
       lcd.backlight();
    lcd.clear();
    lcd.setCursor(0, 0);
     lcd.print("Up");
     Serial.println("up");
     
     digitalWrite(side_3,HIGH);
     digitalWrite(side_4,0);


 Serial.println(digitalRead(side_3));
       Serial.println(digitalRead(side_4));
     Serial.println(digitalRead(bottom_5));
      Serial.println(digitalRead(bottom_6));
       Serial.println("y");
       Serial.println(side_3);
     enable_speedV(EN_side);
     
     
    }
    else if(IR.decodedIRData.decodedRawData==0xAD52FF00){
       lcd.backlight();
    lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("Down");
     Serial.println("down");
     digitalWrite(side_3,0);
     digitalWrite(side_4,HIGH);


 Serial.println(digitalRead(side_3));
       Serial.println(digitalRead(side_4));
     Serial.println(digitalRead(bottom_5));
      Serial.println(digitalRead(bottom_6));
       Serial.println("x");
     enable_speedV(EN_side);
   
      }
      else if(IR.decodedIRData.decodedRawData==0xA55AFF00){
         lcd.backlight();
    lcd.clear();
     lcd.setCursor(0, 0);
        lcd.print("Right");
        Serial.println("right");
        digitalWrite(bottom_6,HIGH);
     digitalWrite(bottom_5,0);


     enable_speedH(EN_bottom);
        }
  else if(IR.decodedIRData.decodedRawData==0xF708FF00){
  lcd.backlight();
    lcd.clear();
         lcd.setCursor(0, 0);
lcd.print("Left");
Serial.println("left");
    digitalWrite(bottom_6,0);
     digitalWrite(bottom_5,HIGH);
       digitalWrite(side_3,0);
     digitalWrite(side_4,0);

     enable_speedH(EN_bottom);
    }
    else if(IR.decodedIRData.decodedRawData==0xE31CFF00){
       lcd.backlight();
    lcd.clear();
      digitalWrite(bottom_6,0);
     digitalWrite(bottom_5,0);
     
       digitalWrite(side_3,0);
     digitalWrite(side_4,0);

      } 
      IR.resume();
  }

}
