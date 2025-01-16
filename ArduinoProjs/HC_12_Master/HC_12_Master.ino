#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <SoftwareSerial.h> 

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

SoftwareSerial HC12(2, 3); // 아두이노 2번을 HC-12 TX Pin에 연결, 3번을 HC-12 RX Pin에 연결.

void setup() { 
  Serial.begin(9600); // 시리얼포트 ↔ computer 
  HC12.begin(9600);   // 시리얼포트 ↔ HC12 
  
  Serial.println("This is 'B' HC-12 Module");

  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
  lcd.setCursor(0,1);
  lcd.print("1602 lcd test");
} 
void loop() { 

  // 시리얼모니터로 수신(입력)데이터가 있을 경우 HC12를 통해 데이터를 발송
  while (Serial.available()) { 
    String input = Serial.readString();
    HC12.println(input);
  } 
  // HC12모듈이 받은 데이터가 있을 경우 시리얼모니터로 출력
  while (HC12.available()) { 
    String input = HC12.readString();
    Serial.println(input);
  } 
  delay (20);
}
