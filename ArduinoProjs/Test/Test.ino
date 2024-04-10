#include <Servo.h>

Servo myservo1;
Servo myservo2;



void setup() {
  Serial.begin(9600);
  myservo1.attach(9);
  myservo2.attach(10); 
}

void loop() {
  int angle;
  if(Serial.available()) {
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
    sscanf(buffer,"%d",&angle);
    angle = angel + 0; //각도 값 수정

    if(angle>=0) {
      myservo1.write(0);
      myservo2.write(180-angle); 
    }  
    else {
      myservo1.write(abs(angle));
      myservo2.write(0); 
    }  
  }  
}
