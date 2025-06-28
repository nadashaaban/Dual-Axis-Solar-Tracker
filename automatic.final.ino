#include <Wire.h>
#include<LiquidCrystal.h>
#include<LiquidCrystal_I2C.h>
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
LiquidCrystal_I2C lcd (0x27,16,2);

float error_up_down=0, last_error_up_down=0, error_left_right=0, last_error_left_right=0, integral_up_down=0, integral_left_right=0, derivative_up_down=0, derivative_left_right=0;
float kp_up_down = 0.28, ki_up_down = 0.01, kd_up_down = 0.0000009;
float kp_left_right = 0.57, ki_left_right = 0, kd_left_right = 0.000001;
int speed_side = 0;
int speed_bottom = 0;

void adjustSideMotor() {
 float reading_up = analogRead(up);
  float reading_down = analogRead(down);

  error_up_down = reading_up - reading_down;
  integral_up_down += error_up_down;
  derivative_up_down = error_up_down - last_error_up_down;

  double output_side = kp_up_down * error_up_down + ki_up_down * integral_up_down + kd_up_down * derivative_up_down;

  output_side = map(output_side, -1023, 1023, -255, 255);
  speed_side = output_side;

  Serial.println(speed_side);
   Serial.println(reading_up);
    Serial.println(reading_down);
    
  if (reading_up - reading_down > 350) {
    lcd.clear();
     lcd.setCursor(0, 0);
        lcd.print("Up");
        
    digitalWrite(side_3, HIGH);
    digitalWrite(side_4, LOW);
  } else if (reading_down - reading_up > 350) {
    digitalWrite(side_3, LOW);
    digitalWrite(side_4, HIGH);
         
    lcd.clear();
     lcd.setCursor(0, 0);
        lcd.print("Down");
  } 
else {
       lcd.backlight();
    lcd.clear();
  digitalWrite(side_3, LOW);
  digitalWrite(side_4, LOW);
  digitalWrite(bottom_5, LOW);
  digitalWrite(bottom_6, LOW);
 analogWrite(EN_side, 0);
 analogWrite(EN_bottom, 0); }
  
  analogWrite(EN_side, abs(speed_side));

  last_error_up_down = error_up_down;



}

void adjustBottomMotor() {
  float reading_left = analogRead(left);
  float reading_right = analogRead(right);
  Serial.println(speed_bottom);
   Serial.println(reading_left);
    Serial.println(reading_right);

  error_left_right = reading_left - reading_right;
  integral_left_right += error_left_right;
  derivative_left_right = error_left_right - last_error_left_right;

  double output_bottom = kp_left_right * error_left_right + ki_left_right * integral_left_right + kd_left_right * derivative_left_right;

  output_bottom = map(output_bottom, -1023, 1023, -255, 255);
  
  speed_bottom = output_bottom;


  if (reading_left - reading_right > 20) {
    digitalWrite(bottom_5, HIGH);
    digitalWrite(bottom_6, LOW);
      // Set the motor speed using PWM
  analogWrite(EN_bottom, abs(speed_bottom)+5);

    lcd.clear();
     lcd.setCursor(0, 0);
        lcd.print("Left");
  } else if (reading_right - reading_left > 20) {
    digitalWrite(bottom_5, LOW);
    digitalWrite(bottom_6, HIGH);
      // Set the motor speed using PWM
  analogWrite(EN_bottom, abs(speed_bottom)-5);
 
    lcd.clear();
     lcd.setCursor(0, 0);
        lcd.print("Right");
}
else { 
       lcd.backlight();
    lcd.clear();
  digitalWrite(side_3, LOW);
  digitalWrite(side_4, LOW);
  digitalWrite(bottom_5, LOW);
  digitalWrite(bottom_6, LOW);
 analogWrite(EN_side, 0);
 analogWrite(EN_bottom, 0); }
 
  last_error_left_right = error_left_right;
  

}

void setup() {
  Serial.begin(9600);
  pinMode(side_3, OUTPUT);
  pinMode(side_4, OUTPUT);
  pinMode(EN_side, OUTPUT);
  pinMode(bottom_5, OUTPUT);
  pinMode(bottom_6, OUTPUT);
  pinMode(EN_bottom, OUTPUT);

  pinMode(up, INPUT);
  pinMode(left, INPUT);
  pinMode(down, INPUT);
  pinMode(right, INPUT);

  digitalWrite(side_3, LOW);
  digitalWrite(side_4, LOW);
  digitalWrite(EN_side, LOW);
  digitalWrite(bottom_5, LOW);
  digitalWrite(bottom_6, LOW);
  digitalWrite(EN_bottom, LOW);
    lcd.init();
 lcd.backlight();
}

void loop() {
float reading_up = analogRead(up);
 float reading_down = analogRead(down);
  float reading_left = analogRead(left);
    float reading_right = analogRead(right);

 


  if (abs(reading_up - reading_down) > 0 ) {
adjustSideMotor();
}
if( abs(reading_left - reading_right) > 0) {
adjustBottomMotor();
}
else {
  digitalWrite(side_3, LOW);
  digitalWrite(side_4, LOW);
  digitalWrite(bottom_5, LOW);
  digitalWrite(bottom_6, LOW);
 analogWrite(EN_side, 0);
 analogWrite(EN_bottom, 0); }
}
