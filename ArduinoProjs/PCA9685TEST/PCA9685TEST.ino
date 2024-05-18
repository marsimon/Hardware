#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

const int numFans = 16;
int lastInput[numFans] = {0}; // 초기값 설정 (원하는 각도) - 팬에 대한 초기값

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(540); // 오작동 한다면 50Hz에서 조금씩 바꿔보기
  pwm.setPWM(0, 0, 2048);
}

void loop() {
// 읽어온 데이터가 있는지 확인
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
    for (int i = 0; i < numFans; i++) {
    pwm.setPWM(i, 0, ra[i]);
    }

    // 현재 입력 값을 저장
    for (int i = 0; i < numFans; i++) {
      lastInput[i] = values[i];
    }

    // 디버깅을 위해 출력
    Serial.print('(');
    for (int i = 0; i < numFans - 1; i++) {
      Serial.print(values[i]);
      Serial.print(',');
    }
    Serial.print(values[numFans - 1]);
    Serial.println(')');
  }

  // 입력이 없을 때에도 이전 입력 값을 유지하도록 팬을 계속 회전
  for (int i = 0; i < numFans; i++) {
  int ra = map(lastInput[i], 0, 255, 0, 4095);
  pwm.setPWM(i, 0, ra);
  }

  delay(10);
}