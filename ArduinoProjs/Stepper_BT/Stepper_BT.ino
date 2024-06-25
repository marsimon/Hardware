#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3);

const int loopCount = 150;//문이 완전히 닫거나 닫히기 위한 회전 수 (테스트 해서 직접 찾아주셔야 해요.)

int ENA=4;
int IN1=5;
int IN2=6;
int ENB=7;
int IN3=8;
int IN4=9;

void setup()
{
  BTSerial.begin(9600);
  Serial.begin(9600);
 pinMode(ENA,OUTPUT);
 pinMode(ENB,OUTPUT);
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 digitalWrite(ENA,HIGH);
 digitalWrite(ENB,HIGH);
}

void forward() {
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(10);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(10);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(10);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(10);
}

void backward() {
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(10);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(10);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(10);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(10);
}

void loop()
{
  if (BTSerial.available()) {
    char c = BTSerial.read();
    Serial.write(c);
    if(c == 'o') {
      for(int i=0;i<loopCount;i++) {
        forward(); //forward와 backward 방향이 맞는지 보고, 아니면 반대.
      }
    }
    else if(c == 'c') {
      for(int i=0;i<loopCount;i++) {
        backward(); 
      }
    }
  }
  if (Serial.available()) {
  char c =Serial.read();
  Serial.write(c);
  BTSerial.write(c);
  }
}
