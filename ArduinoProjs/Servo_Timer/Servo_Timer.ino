#include <Servo.h>  // 서보모터 라이브러리를 불러옵니다.
Servo myservo;      // 서보모터에 myservo라고 이름을 붙여줍니다.
void setup() {
 myservo.attach(3);  // myservo를 9번으로 선언하고 작동할 준비를 합니다.
}
void loop() {
  myservo.write(30);  // myservo를 30도가 되도록 움직입니다.
  delay(60000);        // 60초동안 기다립니다.
  myservo.write(120); // myservo를 150도가 되도록 움직입니다.
  delay(120000);        // 120초동안 기다립니다.
}
