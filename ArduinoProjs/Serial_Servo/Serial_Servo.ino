#include <Servo.h>  // 서보모터 라이브러리를 불러옵니다.
Servo myservo1;      
Servo myservo2;
void setup() {
 myservo1.attach(9);  // myservo를 9번으로 선언하고 작동할 준비를 합니다.
 myservo2.attach(10);
}
void loop() {
  myservo.write(80);  // myservo를 30도가 되도록 움직입니다.
  delay(1000);        // 1초동안 기다립니다.
  myservo.write(90);
  delay(1000);
  myservo.write(100); // myservo를 150도가 되도록 움직입니다.
  delay(1000);        // 1초동안 기다립니다.
}