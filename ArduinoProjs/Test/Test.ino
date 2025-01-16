#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

void setup() {

  Serial.begin(115200);
  unsigned long startTime = millis();  // 현재 시간을 저장
  bool inputReceived = false;
  while (millis() - startTime < 10000) {
    Serial.println(".");
    delay(500);
    if (Serial.available()) {
      inputReceived = true;
      break;  // 입력이 있으면 루프 종료
    }
  }

  //EEPROM.begin(512); 
  if(inputReceived) {
    Serial.println("wow");
  }

  
}

void loop() {
  

}

