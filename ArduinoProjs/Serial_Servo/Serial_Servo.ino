#include <Servo.h>

Servo myservo1;
Servo myservo2;

#define OFFSET 15  //입력받은 각도와 서보모터 차이값. (15가 기본 오차)

void setup() {
  Serial.begin(9600); //시리얼 통신 시작
  myservo1.attach(9);
  myservo2.attach(10); //서보모터 두개 9,10번 연결 후 초기화
  myservo1.write(0);
  myservo2.write(180); 
}

void loop() {
  int angle;
  if(Serial.available()) { //시리얼 통신 입력받기
    char buffer[10];
    int cnt = 0;
    unsigned long start = millis();

    while (millis() - start < 100) {
      if (Serial.available() < 1) {
        continue;
      }
      char data = Serial.read();
      if (data == '\n') {
        buffer[cnt++] = '\0';
        break;
      }
      buffer[cnt++] = data;
    }
     //시리얼 통신 으로 받은 숫자 버퍼에 저장
    sscanf(buffer,"%d",&angle);
    angle = angle + OFFSET; //각도 값 수정
    //시리얼 통신 으로 받은 숫자 각도로 변화 후 저장
    if(angle>=0) { //움직일 각도가 양수인 경우 (오른쪽 방향)
      myservo1.write(0);
      myservo2.write(180-angle); 
    }  
    else { //움직일 각도가 음수인 경우
      myservo1.write(abs(angle));
      myservo2.write(180); 
    }  
  }  
}