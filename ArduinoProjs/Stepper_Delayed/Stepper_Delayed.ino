int dirPin = A4;                            // dirPin을 3으로 설정합니다.
int stepPin = A3;                         // stepPin을 4로 설정합니다.
void setup() {
  pinMode(dirPin, OUTPUT);      // dirPin을 출력핀으로 설정합니다.
  pinMode(stepPin, OUTPUT);    // stepPin을 출력핀으로 설정합니다.
  digitalWrite(dirPin, HIGH);        // dirPin에 HIGH를 출력합니다.
  
  for(int i=0;i<32000;i++) {
    digitalWrite(stepPin, HIGH);      // stepPin에 HIGH를 출력합니다.
    delayMicroseconds(500);        // 500 마이크로초를 쉽니다.
    digitalWrite(stepPin, LOW);      // stepPin에 LOW를 출력합니다.
    delay(1);   
  }
}

void loop() {                           // 1 밀리초를 쉽니다.
}