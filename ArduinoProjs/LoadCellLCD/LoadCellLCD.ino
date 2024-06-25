#include <HX711.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LOADCELL_DOUT_PIN  3
#define LOADCELL_SCK_PIN  2
#define LOADCELL_CALIBRATION -7050.0
#define LBS_to_GRAM 453.6

#define BUTTON_PIN  A0

#define LEDR_PIN  9
#define LEDB_PIN  10
#define LEDG_PIN  11

#define BUZZER_PIN  12


HX711 scale(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN); //DOUT 3, CLK 2

LiquidCrystal_I2C lcd(0x27, 16, 2);

float weight = 0;
float weightThreshold = 500; //기본 기준값

void setup() {
  Serial.begin(9600);

  scale.set_scale(LOADCELL_CALIBRATION);
  scale.tare();	

  lcd.init();
  lcd.backlight();

  pinMode(LEDR_PIN, OUTPUT);
  pinMode(LEDB_PIN, OUTPUT);
  pinMode(LEDG_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LEDR_PIN,HIGH);
  digitalWrite(LEDB_PIN,HIGH);
  digitalWrite(LEDG_PIN,HIGH);
  digitalWrite(BUZZER_PIN,HIGH);

  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {

  weight = scale.get_units(3);
  weight = weight * LBS_to_GRAM;
  lcd.setCursor(0, 0);
  lcd.print("Weight: ");
  lcd.print(weight);
  lcd.print(" g");
  

  int ledOn;
  if (analogRead(BUTTON_PIN) >= 500) {
    weightThreshold = 1500;
    ledOn = 11;
  } else if (analogRead(BUTTON_PIN) >= 300) {
    weightThreshold = 1000;
    ledOn = 10;
  } else if(analogRead(BUTTON_PIN) >= 100){
    weightThreshold = 500;
    ledOn = 9;
  }

  lcd.setCursor(0, 1);
  lcd.print("Setting: ");
  lcd.print(weightThreshold);
  lcd.print(" g");

  if (weight >= weightThreshold) {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(ledOn,LOW);
  } else {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LEDR_PIN,HIGH);
    digitalWrite(LEDB_PIN,HIGH);
    digitalWrite(LEDG_PIN,HIGH);
  }

}
