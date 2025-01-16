#include <ESP8266WiFi.h>
#include <DFRobot_DHT11.h>
#include <SoftwareSerial.h>
#include <Wire.h>

#include "RTClib.h"

// DHT11 설정
DFRobot_DHT11 DHT;
#define DHT11_PIN D4 // GPIO 0 (D3)

// 소프트웨어 시리얼 설정
SoftwareSerial BTSerial(D5, D6);

// RTC 설정
RTC_DS1307 RTC;

// 기상청 서버 설정
const int httpPort = 80;
const char* host = "www.kma.go.kr";
const char* ssid = "MarsHome"; // ksy1234
const char* password = "mars1234"; // ksy51580
const String url = "/w/rss/dfs/hr1-forecast.do?zone=2723068000"; // 지역별 주소 작성

bool awaitingArrivals = true;
bool arrivalsRequested = false;
WiFiClient client;

unsigned long previousMillis = 0;
long long recentVentMillis = -600000;
bool isOpen = false;
// 지역 정보
String Temp = ""; // 온도
String Humi = ""; // 습도
String WfKor = ""; // 날씨(한글)

void setup() {
Serial.begin(115200);
BTSerial.begin(9600);

Wire.begin();
RTC.begin();
//RTC.adjust(DateTime(__DATE__,__TIME__));
connectWiFi();
}

void loop() {

if (Serial.available()) {
String s = Serial.readStringUntil('\n');
Serial.println(s);
if(s.equals("o")) {
BTSerial.write('o');
isOpen=true;
}
else if(s.equals("c")) {
BTSerial.write('c');
isOpen=false;
}
else if(s.equals("비")&&isOpen) {
BTSerial.write('c');
isOpen=false;
}
}

if(millis() - previousMillis > 10000) { //10초마다 측정
previousMillis = millis();
}
else return;
getData();
Serial.println("-----------------");
Serial.println("온도: " + Temp);
Serial.println("습도: " + Humi);
Serial.print("날씨: ");
Serial.println("(" + WfKor + ")");
Serial.println("-----------------");

DHT.read(DHT11_PIN);
Serial.print("temp:");
Serial.print(DHT.temperature);
Serial.print(" humi:");
Serial.println(DHT.humidity);

DateTime now = RTC.now();
Serial.print(" hour:");
Serial.println(now.hour());

if (now.hour() == 12&&!isOpen) { //오후 3시에 환기
if(millis()-recentVentMillis > 610000) { //최근 환기 시각으로부터 1분 이상 지났으면 환기

Serial.print("시간 환기:");
recentVentMillis =millis();
BTSerial.write('o');
delay(14000);
BTSerial.write('c');
}
}
float h = Humi.toFloat();
if(DHT.humidity<40||DHT.humidity>60) { //현재 집 습도가 낮거나 높으면 환기
if(millis()-recentVentMillis > 120000) {
recentVentMillis =millis();
if(h>25&&h<60) {
BTSerial.write('o');
delay(14000);
BTSerial.write('c');
delay(14000);
}
}
}
if(h>95&&isOpen) { //밖이 습하고 문 열려있으면 닫기
BTSerial.write('c');
}
}

void getData() {
if (client.connect(host, httpPort)) {
client.print(String("GET ") + url + " HTTP/1.1\r\n" +
"Host: " + host + "\r\n" +
"Connection: close\r\n\r\n");
delay(50);
}

while (client.connected()) {
String line = client.readStringUntil('\n');
if (line == "\r") {
break;
}
}

while (client.available()) {
String line = client.readStringUntil('\n');

// 온도
int temp = line.indexOf("</temp>");
if (temp > 0) {
String tmp_str = "<temp>";
String wt_temp = line.substring(line.indexOf(tmp_str) + tmp_str.length(), temp);
Temp = wt_temp;

Serial.println(Temp);
}

// 날씨 한글
int wfKor = line.indexOf("</wfKor>");
if (wfKor > 0) {
String tmp_str = "<wfKor>";
String wt_wfKor = line.substring(line.indexOf(tmp_str) + tmp_str.length(), wfKor);
WfKor = wt_wfKor;

}

// 습도
int reh = line.indexOf("</reh>");
if (reh > 0) {
String tmp_str = "<reh>";
String wt_humi = line.substring(line.indexOf(tmp_str) + tmp_str.length(), reh);
Humi = wt_humi;
break;
}
}
}

void connectWiFi() {

  Serial.println("SSID: ");
  Serial.print(ssid);
  Serial.println("PW: ");
  Serial.print(password);
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

}