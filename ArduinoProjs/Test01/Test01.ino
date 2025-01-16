#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

// EEPROM에 저장할 데이터의 최대 길이 설정
#define DEVICE_NAME_MAX_LENGTH 32
#define SSID_MAX_LENGTH 32
#define PASSWORD_MAX_LENGTH 32
#define START_ADDRESS 0  // EEPROM의 시작 주소
#define WATER_LEVEL 25 //센서 부저 울릴 거리 기준

char deviceName[DEVICE_NAME_MAX_LENGTH];
char ssid[SSID_MAX_LENGTH];
char password[PASSWORD_MAX_LENGTH];

#define ECHO_PIN 14 //D5
#define TRIG_PIN 12 //D6
#define BUZZ_PIN 13 //D7
#define LEDR_PIN 5 //D1
#define LEDG_PIN 4 //D2
#define BTN_PIN 0 //D3

const char* host = "www.machaboo.com";   // 서버 도메인 또는 IP
const int httpsPort = 3000;   // HTTPS 포트 (기본: 443)

bool alarmOn = false;

unsigned long muteTime=10000000;
unsigned long lastSent=0;
void setup() {

  Serial.begin(115200);
  EEPROM.begin(512); 
  pinMode(TRIG_PIN, OUTPUT);   // trigPin 핀을 출력핀으로 설정합니다.
  pinMode(ECHO_PIN, INPUT);    // echoPin 핀을 입력핀으로 설정합니다.
  pinMode(BUZZ_PIN, OUTPUT);  
  pinMode(LEDR_PIN, OUTPUT);   
  pinMode(LEDG_PIN, OUTPUT);   
  pinMode(BTN_PIN, INPUT);

  soundBuzz(1);
  unsigned long startTime = millis();  // 현재 시간을 저장
  bool inputReceived = false;
  while (millis() - startTime < 15000) {
    Serial.println("Waiting for input..");
    delay(500);
    if (Serial.available()) {
      inputReceived = true;
      break;  // 입력이 있으면 루프 종료
    }
  }
  
  if(inputReceived) {
    getDeviceInformation();
    connectWiFi();
  }

  
}

void loop() {
  // 주기적으로 WiFi 연결 상태를 확인하고, 필요 시 재연결 시도
  
   
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi disconnected, trying to reconnect...");
    digitalWrite(LEDG_PIN, LOW);
    connectWiFi();
    return;
  } else {
    digitalWrite(LEDG_PIN, HIGH);
  }


  // 필요한 작업 수행
  //주기적으로 수위센서를 확인하고, 웹서버에 전송하기. 
  //일정 수위 이하에서 부저 on 
  //버튼 입력 시 부저 off

  int distance = getDistance();
  Serial.println(distance);
  
  unsigned long cTime = millis();

  if (digitalRead(BTN_PIN) == LOW) {
    muteTime = cTime;
  }

  if(alarmOn && distance > WATER_LEVEL - 3) {
    if(cTime>=muteTime&& cTime < muteTime+600000) {
      
    }
    else {
      soundBuzz(2);
    }
  }
  else if (distance > WATER_LEVEL) {
    alarmOn = true;
    digitalWrite(LEDR_PIN, HIGH);
    if(cTime>=muteTime&& cTime < muteTime+600000) {
      
    }
    else {
      soundBuzz(2);
    }
  }

  else {
    alarmOn = false;
    digitalWrite(LEDR_PIN, LOW);
  }

  unsigned long gap;
  gap =(lastSent > cTime) ? lastSent - cTime : cTime - lastSent;
  if(gap > 20000&&distance>15) {
    SendDeviceData(distance);
    lastSent = cTime;
  }

}


int getDistance() {
  int distSum=0,cnt=0;
  for(int i=0;i<5;i++) {
    long duration, distance;                   // 각 변수를 선언합니다.
    digitalWrite(TRIG_PIN, LOW);                 // trigPin에 LOW를 출력하고
    delayMicroseconds(2);                    // 2 마이크로초가 지나면
    digitalWrite(TRIG_PIN, HIGH);                // trigPin에 HIGH를 출력합니다.
    delayMicroseconds(10);                  // trigPin을 10마이크로초 동안 기다렸다가
    digitalWrite(TRIG_PIN, LOW);                // trigPin에 LOW를 출력합니다.
    duration = pulseIn(ECHO_PIN, HIGH);   // echoPin핀에서 펄스값을 받아옵니다.
 
    distance = duration * 17 / 1000;          //  duration을 연산하여 센싱한 거리값을 distance에 저장합니다.
    Serial.println(distance);
    if (distance >= 200 || distance <= 0)       // 거리가 200cm가 넘거나 0보다 작으면
    {

      Serial.println("Distance out of boudary");   // 에러를 출력합니다.

    }
    else   // 거리가 200cm가 넘지 않거나 0보다 작지 않으면
    {
      cnt++;
      distSum += distance;
    }
    delay(1000);
  }

  if(cnt==0) return 0;
  return distSum/cnt;
}


void SendDeviceData(int dist) {
  WiFiClientSecure client;
  client.setInsecure();

  Serial.print("Connecting to ");
  Serial.println(host);

  if (!client.connect(host, httpsPort)) {
    Serial.println("Connection failed");
    return;
  }

  // POST 요청용 JSON 형식의 body 데이터 생성
  String postData = "{\"device\":\"" + String(deviceName) + "\", \"litter\":" + String(dist) + "}";
  Serial.println(postData);
  // POST 요청 생성
  String url = "/api/analysis/residual";  // API 엔드포인트 경로

  client.println("POST " + url + " HTTP/1.1");
  client.println("Host: " + String(host));
  client.println("User-Agent: ESP8266");
  client.println("Content-Type: application/json");
  client.println("Connection: close");
  client.print("Content-Length: ");
  client.println(postData.length());
  client.println();
  client.println(postData);

  /*
  // 서버 응답 읽기
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("Headers received");
      break;
    }
  }

  // 서버 응답 내용 출력
  String response = client.readString();
  Serial.println("Response: ");
  Serial.println(response);
  */
  
}

void getDeviceInformation() {
  String deviceName, ssid, password;

  // 기기명 입력
  //Serial.print("Enter device name: ");
  deviceName = readSerialInput(DEVICE_NAME_MAX_LENGTH);
  Serial.println("deviceName :");
  Serial.print(deviceName);

  // WiFi SSID 입력
  //Serial.print("Enter WiFi SSID: ");
  ssid = readSerialInput(SSID_MAX_LENGTH);
  Serial.println("ssid :");
  Serial.print(ssid);
  // WiFi 비밀번호 입력
  //Serial.print("Enter WiFi Password: ");
  password = readSerialInput(PASSWORD_MAX_LENGTH);
  Serial.println("password :");
  Serial.print(password);

  // 입력된 데이터를 EEPROM에 저장
  saveToEEPROM(deviceName, ssid, password);
}

String readSerialInput(int maxLength) {
  String input = "";

  while (true) {
    if (Serial.available()) {
      char c = Serial.read();
      if (c == '\n' || c == '\r') {
        break;
      }
      input += c;
      if (input.length() >= maxLength) {
        break;
      }
    }
  }
  return input;
}

void saveToEEPROM(String deviceName, String ssid, String password) {
  int addr = START_ADDRESS;

  // 기기명 저장
  for (int i = 0; i < DEVICE_NAME_MAX_LENGTH; ++i) {
    EEPROM.write(addr++, i < deviceName.length() ? deviceName[i] : 0);
  }

  // SSID 저장
  for (int i = 0; i < SSID_MAX_LENGTH; ++i) {
    EEPROM.write(addr++, i < ssid.length() ? ssid[i] : 0);
  }

  // 비밀번호 저장
  for (int i = 0; i < PASSWORD_MAX_LENGTH; ++i) {
    EEPROM.write(addr++, i < password.length() ? password[i] : 0);
  }

  EEPROM.commit();
  Serial.println("Device information saved to EEPROM.");
}

void connectWiFi() {

  readFromEEPROM(deviceName, ssid, password);

  Serial.println("Connecting to WiFi...");
  Serial.println("Device Name: ");
  Serial.println(deviceName);
  Serial.println("SSID: ");
  Serial.println(ssid);
  Serial.println("PW: ");
  Serial.println(password);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  WiFi.begin(ssid, password);

  int max_attempts = 10;
  int attempt = 0;
  while (WiFi.status() != WL_CONNECTED && attempt < max_attempts) {
    delay(1000);
    Serial.print(".");
    attempt++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi connected!");
    soundBuzz(3);
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  }

  else {
    WiFi.disconnect();
  }

}

void soundBuzz(int n) {

  for(int i=0;i<n;i++) {
    digitalWrite(BUZZ_PIN, HIGH);                 
    delay(500);                   
    digitalWrite(BUZZ_PIN, LOW); 
  }

}

void readFromEEPROM(char* deviceName, char* ssid, char* password) {
  int addr = START_ADDRESS;

  // 기기명 읽기
  for (int i = 0; i < DEVICE_NAME_MAX_LENGTH; ++i) {
    deviceName[i] = EEPROM.read(addr++);
  }

  // SSID 읽기
  for (int i = 0; i < SSID_MAX_LENGTH; ++i) {
    ssid[i] = EEPROM.read(addr++);
  }

  // 비밀번호 읽기
  for (int i = 0; i < PASSWORD_MAX_LENGTH; ++i) {
    password[i] = EEPROM.read(addr++);
  }
}
