int dirPin = A4;                      
int stepPin = A3;                   
void setup() {
  pinMode(dirPin, OUTPUT);      // dirPin을 출력핀으로 설정합니다.
  pinMode(stepPin, OUTPUT);    // stepPin을 출력핀으로 설정합니다.
  digitalWrite(dirPin, HIGH);        // dirPin에 HIGH를 출력합니다.
}

void loop() {                           // 1 밀리초를 쉽니다.
  for(int i=0;i<32000;i++) { //20분에 1회전 1200 000 ms 한바퀴는 32000스텝, 37.5 미리초마다 1스텝
    digitalWrite(stepPin, HIGH);      // stepPin에 HIGH를 출력합니다.
    delayMicroseconds(500);        // 500 마이크로초를 쉽니다.
    digitalWrite(stepPin, LOW);      // stepPin에 LOW를 출력합니다.
    delay(36);   
  }
}