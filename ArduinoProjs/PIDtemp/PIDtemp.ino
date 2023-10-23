#include <PID_v1.h>

#define DIAL_START_PIN 4 //다이얼 디지털핀 시작 핀
#define TEMP_PIN A0 //온도센서핀
#define PWM_PIN 3 // 릴레이 출력핀

double Setpoint, Input, Output;

double Kp=2, Ki=5, Kd=1;

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  Input = analogRead(TEMP_PIN);
  Setpoint = 100;
  for(int i=0;i<12;i++) {
    pinMode(DIAL_START_PIN+i,INPUT_PULLUP);
  }
  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

void loop()
{
  for(int i=0;i<12;i++) {
    if(digitalRead(DIAL_START_PIN+i)==LOW) {
      Setpoint = 30 + 5 * i; //다이얼 온도 설정. 기본 설정은 30도부터 다이얼 1칸당 10도씩 증가
    }
  }
  Input = (analogRead(TEMP_PIN) * 5.0 / 1024.0 - 0.5)*100; //센서 입력 섭씨 온도
  myPID.Compute();
  analogWrite(PWM_PIN, Output);
}
