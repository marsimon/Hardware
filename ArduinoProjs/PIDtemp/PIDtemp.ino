#include <PID_v1.h>

#define DIAL_START_PIN1 4 //다이얼1 디지털핀 시작 핀
#define DIAL_START_PIN2 18 //다이얼2 디지털핀 시작 핀
#define START_PIN1 35 //시작 버튼핀
#define START_PIN2 36 
#define TEMP_PIN1 A0 //온도센서핀
#define TEMP_PIN2 A1 //온도센서핀
#define PWM_PIN 40 // 릴레이1 출력핀
#define PWM_PIN 41 // 릴레이2 출력핀
#define LED1_PIN 42 // LED1 출력핀
#define LED2_PIN 43 // LED2 출력핀

double Setpoint, Input, Output;

double Kp=2, Ki=5, Kd=1;

PID myPID1(&Input1, &Output1, &Setpoint1, Kp, Ki, Kd, DIRECT);
PID myPID2(&Input2, &Output2, &Setpoint2, Kp, Ki, Kd, DIRECT);

unsigned long timer1=0, timer2=0;

void setup()
{
  Input1 = analogRead(TEMP_PIN1);
  Input2 = analogRead(TEMP_PIN2);
  Setpoint1 = 38;
  Setpoint2 = 38;
  for(int i=0;i<12;i++) {
    pinMode(DIAL_START_PIN1+i,INPUT_PULLUP);
    pinMode(DIAL_START_PIN2+i,INPUT_PULLUP);
  }
  pinMode(START_PIN1,INPUT_PULLUP);
  pinMode(START_PIN2,INPUT_PULLUP);
  pinMode(LED1_PIN,OUTPUT);
  pinMode(LED2_PIN,OUTPUT);
  //turn the PID on
  myPID1.SetMode(AUTOMATIC);
  myPID2.SetMode(AUTOMATIC);

}

void loop()
{
  for(int i=0;i<12;i++) {
    if(digitalRead(DIAL_START_PIN1+i)==LOW) {
      Setpoint1 = 38 + 1 * i; 
    }
    if(digitalRead(DIAL_START_PIN2+i)==LOW) {
      Setpoint2 = 38 + 1 * i; 
    }
  }

  if(digitalRead(START_PIN1)==LOW) {
    timer1=millis()+180000;
  }
  if(digitalRead(START_PIN2)==LOW) {
    timer2=millis()+180000;
  }

  if(timer1>millis()) {
    Input1 = (analogRead(TEMP_PIN1) * 5.0 / 1024.0 - 0.5)*100; //센서 입력 섭씨 온도
    myPID1.Compute();
    analogWrite(PWM_PIN1, Output);
    digitalWrite(LED1_PIN,HIGH);
  }
  else {
    analogWrite(PWM_PIN1, 0);
    digitalWrite(LED1_PIN,LOW);
  }

  if(timer2>millis()) {
    Input2 = (analogRead(TEMP_PIN2) * 5.0 / 1024.0 - 0.5)*100; //센서 입력 섭씨 온도
    myPID2.Compute();
    analogWrite(PWM_PIN2, Output);
    digitalWrite(LED2_PIN,HIGH);
  }
  else {
    analogWrite(PWM_PIN2, 0);
    digitalWrite(LED2_PIN,LOW);
  }
}
