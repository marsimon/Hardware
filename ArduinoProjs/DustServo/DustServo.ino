#include "DHT.h"
#include <Servo.h>

#define DHTPIN 7     // DHT11이 연결된 핀

#define DHTTYPE DHT11   // DHT 11, DHT시리즈중 11을 선택합니다.

Servo myservo;

int measurePin = A1;          // measurePin을 0으로 설정합니다.
int ledPower = 2;             // ledPower를 2로 설정합니다.
 
int samplingTime = 280;    // samplingTime을 280으로 설정합니다.
int deltaTime = 40;           // deltaTime을 40으로 설정합니다.
int sleepTime = 9680;       // sleepTime을 9690으로 설정합니다.
 
float voMeasured = 0;      // voMeasured를 0으로 설정합니다.
float calcVoltage = 0;       // calcVoltage를 0으로 설정합니다.
float dustDensity = 0;       // dustDensity를 0으로 설정합니다.

bool closed = true;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(ledPower,OUTPUT);
  myservo.attach(9);
  myservo.write(90);
  dht.begin();
}

void loop() {
  delay(2000);

  digitalWrite(ledPower,LOW);                               // ledPower를 LOW로 설정합니다.
  delayMicroseconds(samplingTime);                    // samplingTime(280) 마이크로초만큼 지연합니다.
 
  voMeasured = analogRead(measurePin);             //  measurePin의 아날로그 값을 받아 voMeasured에 저장합니다.
 
  delayMicroseconds(deltaTime);                          // deltaTime(40) 마이크로초만큼 지연합니다.
  digitalWrite(ledPower,HIGH);                              // ledPower를 HIGH로 설정합니다.
  delayMicroseconds(sleepTime);                        // sleepTime(9680) 마이크로초만큼 지연합니다.
 
  calcVoltage = voMeasured * (5.0 / 1024.0);         // voMeasured의 값을 5.0/1024.0을 곱하여 calcVoltage에 저장합니다.
 
  dustDensity = (0.17 * calcVoltage - 0.1) * 1000;   // calcVoltage 값에 0.17을 곱하고 -0.1을 더합니다. (mg/m3)
  Serial.print(dustDensity);                             
  Serial.println(" ug/m3");  //먼지 농도 출력                   
  
  float h = dht.readHumidity();// 습도를 측정합니다.
  float t = dht.readTemperature();// 온도를 측정합니다.
  float f = dht.readTemperature(true);// 화씨 온도를 측정합니다.

  // 값 읽기에 오류가 있으면 오류를 출력합니다.
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  
  float hic = dht.computeHeatIndex(t, h, false); //측정한 값으로 온도 계산

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("/");
  
  int bright = analogRead(A0); //밝기 측정
  Serial.print("Brightness : ");
  Serial.print(bright);
  Serial.print("/");

  if (h>40.0f) {
    
    //습도가 70 이상인 경우 
    if(closed) return;
    myservo.write(120); //서보모터 1초간 시계방향 작동하여 문 닫기 
    delay(1000);
    myservo.write(90);
    closed= true;
  }
  else if(dustDensity>30.0f) {
    //미세먼지가 30 이상인 경우 
    
    if(closed) return;
    myservo.write(120); //서보모터 1초간 시계방향 작동하여 문 닫기 
    delay(1000);
    myservo.write(90);
    closed= true;
  }
  else if(bright >1000) {
    if(closed) return;
    // 밝기 센서 1000 이상의 값(높을수록 어두움, 어두운 경우) 문 닫기
    myservo.write(120); //서보모터 1초간 시계방향 작동하여 문 닫기 
    delay(1000);
    myservo.write(90);
    closed= true;
  }
  else if(closed) { //위의 경우를 제외하고, 문이 닫혀있는 경우
    myservo.write(60); //서보모터 1초간 시계방향 작동하여 문 열기 
    delay(1000);
    myservo.write(90);
    closed= false;
  }
  Serial.print(closed);
}
