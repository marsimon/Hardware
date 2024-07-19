#include <Servo.h> 
  
Servo linearServo;
Servo clawServo;

#define PIN_SERVO_LINEAR 6 //서보 직선 운동 핀
#define PIN_SERVO_CLAW 9 //서보 집게 핀
#define PIN_BUTTON 2 //버튼 핀
 
int clawPos = 0;  
int linearPos = 1;

int clawStep = 1; //집게의 한 스텝당 움직일 각도 크기
int linearStep = 1; //직선 움직임의 한 스텝당 움직일 거리 (%)

int delayms = 20; //한번 움직임 후 딜레이 (ms)

void SetStrokePerc(float strokePercentage)
{
  if ( strokePercentage >= 1.0 && strokePercentage <= 99.0 )
  {
    int usec = 1000 + strokePercentage * ( 2000 - 1000 ) / 100.0 ;
    linearServo.writeMicroseconds( usec );
  }
}
 
void setup() 
{ 
  linearServo.attach(PIN_SERVO_LINEAR);
  clawServo.attach(PIN_SERVO_CLAW);
  pinMode(PIN_BUTTON,INPUT_PULLUP);
} 
  
 
void loop() 
{ 
  if(digitalRead(PIN_BUTTON)==LOW) {
    clawPos+=clawStep;
    if(clawPos==180||clawPos==0) clawStep = -clawStep;
    clawServo.write(clawPos);

    linearPos+=linearStep;
    if(linearPos==99||linearPos==1) linearStep = -linearStep;
    SetStrokePerc(linearPos);
  }

  else if(clawPos!=0){
    clawServo.write(0); 
    clawPos=0;
  }
  else if(linearPos!=1) {
    SetStrokePerc(1);
    linearPos=1;
  }

  delay(delayms);
}