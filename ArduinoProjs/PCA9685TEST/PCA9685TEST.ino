#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
const int numFans = 16;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
  for(int i=0;i<16;i++) {
    pwm.setPWM(i, 0, 4095);
  }
  delay(1000);
  pwm.setPWMFreq(480);
  for(int i=0;i<16;i++) {
    pwm.setPWM(i, 0, 2048);
  }
}

void loop() {
  if (Serial.available()) {
String input = Serial.readStringUntil('\n');
int values[numFans]; // 각 팬에 대한 입력값 배열

// 입력 값을 파싱하여 정수로 변환하여 배열에 저장
int startIndex = 0;
for (int i = 0; i < numFans; i++) {
values[i] = input.substring(startIndex).toInt();
startIndex = input.indexOf(',', startIndex) + 1;
}

// 입력 값을 0에서 255로 제한
for (int i = 0; i < numFans; i++) {
values[i] = constrain(values[i], 0, 255);
}

// PWM 값의 범위 조정 (예: 0에서 4095)
int ra[numFans]; // 각 팬에 대한 PWM 값 배열
for (int i = 0; i < numFans; i++) {
ra[i] = map(values[i], 0, 255, 0, 4095);
}

// 각 팬에 대해 PWM 값 설정
  for (dint i = 0; i < numFans; i++) {
      pwm.setPWM(i, 0, ra[i]);
    }
  }
}