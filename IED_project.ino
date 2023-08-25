#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "helper/motor.h"
#include "helper/target_sensors.h"
#include "helper/ultrasound.h"
#include "logic_gen.h"
#include "movements.h"

LiquidCrystal_I2C lcd(0x27, 16, 2); // 16 char, 2 line display


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Program starting");
  setup_target_sensors();
  setup_motor();
  setup_ultrasound();
  setup_logic();
  delay(150); //remove for faster start..?
  lcd.clear();

}

//unsigned int score = 0;
void loop() {
start:
  generateSeq();
  lcd.clear();
  unsigned long theEnd = millis() + 10000;
  while(theEnd > millis()) {
    lcd.setCursor(0, 0);
    lcd.print(displayEqn());
    lcd.print("   ");
    lcd.print((theEnd - millis())/1000);
    lcd.setCursor(0, 1);
    lcd.print("x=");
    lcd.print(hit_a);
    lcd.print(" y=");
    lcd.print(hit_b); /*
    lcd.print("   ");
    lcd.print(score); */
    long val = distanceUltra();
    Serial.println(displayEqn());
    Serial.println(val);
    if(15 > val) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("too close! back up!");
      backward(1);
      delay(1000);
      brake();
      shakeHead(0.7, 0.7);
      goto start;
    }
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  if(checkAns(hit_a, hit_b)) {
    //score++;
    lcd.print("CORRECT!");
    spin(1);
  } else {
    lcd.print("WRONG!");
    shakeHead(0.7, 0.7);
  }
  hit_a = 0;
  hit_b = 0;
}
