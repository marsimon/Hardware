#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>


#define RLED_PIN D5
#define GLED_PIN D4
#define BLED_PIN D3

#define BTN_PIN D1

char DEVICE_NO = '1'; //슬레이브 기기번호

const char* masterAdd = "192.168.128.253"; //마스터 주소
const char* ssid     = "TastyWifi";//WIFI 이름
const char* password = "mars1234";//WIFI 비밀번호

IPAddress ip(192,168,128,100);
IPAddress gateway(192, 168, 128,100);
IPAddress subnet(255, 255, 255, 0);

ESP8266WebServer server(80);

bool reserved = false;
bool prevState = false,state=true,check = false;
int seat= 0; // 좌석 상태. (0 예약 X현재 비어있음.) (1 예약 O 현재 비어있음) (2. 예약X 누가 앉아있음.) (3. 예약O , 앉아있음)

void setup(void){
  pinMode(RLED_PIN,OUTPUT);
  pinMode(GLED_PIN,OUTPUT);
  pinMode(BLED_PIN,OUTPUT);

  digitalWrite(RLED_PIN,HIGH);
  digitalWrite(GLED_PIN,HIGH);
  digitalWrite(BLED_PIN,HIGH);
  pinMode(BTN_PIN,INPUT_PULLUP); //LED 핀 설정
  Serial.begin(115200);
  delay(1000);
  WiFi.disconnect();

  Serial.print("Connecting to ");

  Serial.println(ssid);

  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password); //WIFI 연결 및 설정

  Serial.println(WiFi.SSID());

  WiFi.setAutoConnect(true); //자동 접속 설정

  WiFi.setAutoReconnect(true); //자동 재접속 설정 

  WiFi.waitForConnectResult();

  Serial.println(WiFi.localIP());
 

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);

    Serial.print(".");

  } // 연결 완료 까지 대기

  Serial.println("");

  Serial.print("Connected to ");

  Serial.println(WiFi.SSID());

  Serial.print("IP address: ");

  Serial.println(WiFi.localIP()); //WIFI 연결 정보 출력

  server.on("/On", [](){ //서버 IP로 /On 도메인이 왔을 때 실행할 문장
    server.send(200, "text/html", " ");
    reserved=true;
    check = true;
  });

  server.on("/Off", [](){ //서버 IP로 /Off 도메인이 왔을 때 실행할 문장
    server.send(200, "text/html", " ");
    reserved=false;
    check = true;
  });

  server.begin();

  Serial.println("HTTP server started");

}

void SendState() { //마스터 서버로 현재 기기 정보를 전송하는 함수 
    if (WiFi.status() == WL_CONNECTED) {    
    WiFiClient client;
    HTTPClient http; 
    String add = String("http://")+masterAdd+String("/state");
    Serial.println(add);
    http.begin(client,add);  // 마스터 서버의 IP로 통신 시작
    
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String httpRequestData = "DevNum=" + String(DEVICE_NO)+"&State="+String(seat); // POST 데이터에 기기번호와 LED 정보를 넣어 전송
    int httpResponseCode = http.POST(httpRequestData); // POST 요청 전송

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    http.end(); 
    }
    delay(100);
}

void loop(void){
  state = digitalRead(BTN_PIN);
  server.handleClient();//클라이언트 접속을 관리합니다.
  if(!(prevState!=state||check)) return; 
  
  if(state==LOW) { //state는 현재 버튼의 상태. LOW가 눌렸을 때임. 이때 LED를 변경하고 마스터 서버에 정보를 갱신한다. 
    if(reserved) {
      seat=3;
      digitalWrite(RLED_PIN,HIGH);
      digitalWrite(GLED_PIN,LOW);
      digitalWrite(BLED_PIN,HIGH);
      SendState();
    }
    else {
      seat=2;
      digitalWrite(RLED_PIN,LOW);
      digitalWrite(GLED_PIN,HIGH);
      digitalWrite(BLED_PIN,HIGH);
      SendState();
    }
  } 
  if(state==HIGH&&check) { //마찬가지로 버튼이 다시 떨어졌을 때 혹은 마스터 서버에 의해 상태가 변경됬을때 LED 변경
    if(reserved) {
      seat=1;
      digitalWrite(RLED_PIN,HIGH);
      digitalWrite(GLED_PIN,HIGH);
      digitalWrite(BLED_PIN,LOW);
      SendState();
    }
    else {
      seat=0;
      digitalWrite(RLED_PIN,HIGH);
      digitalWrite(GLED_PIN,HIGH);
      digitalWrite(BLED_PIN,HIGH);
      SendState();
    }
  }
  check = false;
  prevState=state;
}

