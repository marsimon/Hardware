#include <PID_v1.h>

#define DIAL_START_PIN 4
#define TEMP_PIN A0
#define PWM_PIN 3

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
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
      Setpoint = 512 + 10 * i;
    }
  }
  Input = analogRead(TEMP_PIN);
  myPID.Compute();
  analogWrite(PWM_PIN, Output);
}
