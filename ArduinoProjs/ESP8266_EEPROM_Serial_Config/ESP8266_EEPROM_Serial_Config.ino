#include <EEPROM.h>
#include <ESP8266WiFi.h>

// EEPROM에 저장할 데이터의 최대 길이 설정
#define DEVICE_NAME_MAX_LENGTH 32
#define SSID_MAX_LENGTH 32
#define PASSWORD_MAX_LENGTH 32
#define START_ADDRESS 0  // EEPROM의 시작 주소

void setup() {
  Serial.begin(115200);
  EEPROM.begin(512);  // EEPROM 초기화 (512 바이트)

  Serial.println("Booting...");

  // 저장된 WiFi 정보로 연결 시도
  connectWiFi();

  // WiFi 연결 실패 시 새 정보를 입력받음
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Enter new device information:");
    getDeviceInformation();
    connectWiFi();  // 입력된 정보로 다시 연결 시도
  }
}

void loop() {
  // 주기적으로 WiFi 연결 상태를 확인하고, 필요 시 재연결 시도
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi disconnected, trying to reconnect...");
    connectWiFi();
  }

  // 필요한 작업 수행
  delay(10000);  // 10초 대기
}

void getDeviceInformation() {
  String deviceName, ssid, password;

  // 기기명 입력
  Serial.print("Enter device name: ");
  deviceName = readSerialInput(DEVICE_NAME_MAX_LENGTH);
  Serial.println(deviceName);

  // WiFi SSID 입력
  Serial.print("Enter WiFi SSID: ");
  ssid = readSerialInput(SSID_MAX_LENGTH);
  Serial.println(ssid);

  // WiFi 비밀번호 입력
  Serial.print("Enter WiFi Password: ");
  password = readSerialInput(PASSWORD_MAX_LENGTH);
  Serial.println(password);

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
  char deviceName[DEVICE_NAME_MAX_LENGTH];
  char ssid[SSID_MAX_LENGTH];
  char password[PASSWORD_MAX_LENGTH];

  readFromEEPROM(deviceName, ssid, password);

  Serial.println("Connecting to WiFi...");
  Serial.print("Device Name: ");
  Serial.println(deviceName);
  Serial.print("SSID: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  int max_attempts = 20;
  int attempt = 0;
  while (WiFi.status() != WL_CONNECTED && attempt < max_attempts) {
    delay(500);
    Serial.print(".");
    attempt++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nFailed to connect to WiFi.");
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
